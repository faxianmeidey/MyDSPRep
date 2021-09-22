#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QByteArray>
#include<QDebug>
#include<QString>
#include<QtNetwork>
#include<QTimer>
#include<QFile>
#include<QFileDialog>
#include<QFileInfo>
#include<QMessageBox>

//初始化构造函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->RcvtableView->setStyleSheet("background:rgb(128,128,128)");
    ui->StateusBrowser->setStyleSheet("background:rgb(128,128,128)");
    ui->IPlineEdit->setText("192.168.2.122");
    ui->PortlineEdit->setText("8080");

    ui->TarIPlineEdit->setText("192.168.2.178");
    ui->TarPortlineEdit->setText("4001");

    theModel=new QStandardItemModel(this);
    QStringList lstr;
    lstr<<"报文ID"<<"长度"<<"数据";
    theModel->setHorizontalHeaderLabels(lstr);
    ui->RcvtableView->setModel(theModel);
    ui->RcvtableView->setColumnWidth(0,80);
    ui->RcvtableView->setColumnWidth(1,60);
    ui->RcvtableView->setColumnWidth(2,179);

    dspConnectTimer=new QTimer(this);
    sendtimer= new QTimer(this);
    connect(dspConnectTimer,&QTimer::timeout,this,&MainWindow::timerDspConnectSlot);
    connect(sendtimer,&QTimer::timeout,this,&MainWindow::timerSendSlot);
    dspConnectFlag=0;
    ui->progressBar->setRange(0,HexData.size());
    ui->progressBar->setValue(0);
    ui->StateusBrowser->append("1、请在节点开机10S内连接端口、连接DSP，10S内无操作转应用程序!");
    ui->StateusBrowser->append(" ");
    ui->StateusBrowser->append("2、在点击DSP连接之前，请输入烧写节点十进制ID号！");
}


MainWindow::~MainWindow()
{
    delete ui;
}


//Qtabel添加一行
QList<QStandardItem*>MainWindow::AddRowRecv(union Msg msg)
{
   QList<QStandardItem *> Rowtext;

   QString id=QString::number(msg.message.msgid,10).toUpper();
   QString len=QString::number(msg.message.type,16).toUpper();
   QString data=hex2Str(msg.message.data,8);
   Rowtext<<new QStandardItem(id)<<new QStandardItem(len)<<new QStandardItem(data);
   return Rowtext;
}

//udp初始化
void MainWindow::UdpConnectInit()
{
    QString ip;
    uint16_t port;
    ip=ui->IPlineEdit->text();
    port=ui->PortlineEdit->text().toUInt();
    receiver=new QUdpSocket(this);
    sender=new QUdpSocket(this);
    connect(receiver,&QUdpSocket::readyRead,this,&MainWindow::processPending);
    receiver->open(QIODevice::Append);
    if(receiver->bind(QHostAddress(ip),port,QUdpSocket::DontShareAddress)==true)
    {
        ui->StateusBrowser->append("UDP绑定成功");
    }
    else
    {
         ui->StateusBrowser->append("UDP绑定失败");
    }
}


//udp接收数据处理
void MainWindow::processPending()
{
    QByteArray  Array;
    QByteArray Temp;
    while(receiver->hasPendingDatagrams())
    {
      Array.resize(receiver->pendingDatagramSize());
      receiver->readDatagram(Array.data(),Array.size());
    }
 //如何直接赋值数组
     for(int i=0;i<13;i++)
     {
         TempMsg.data[i]=Array[i];
     }
      TempMsg.message.msgid = qToBigEndian(TempMsg.message.msgid);
      theModel->appendRow(AddRowRecv(TempMsg));

     if(TempMsg.message.data[5]==0x55&&TempMsg.message.data[6]==0xbb)
     {
         if(TempMsg.message.data[7]==0x02)
         {
            ui->StateusBrowser->append("DSP已连接");
            dspConnectFlag=1;
            sendtimer->stop();
         }

         if(TempMsg.message.data[7]==0x01)
         {
            ui->StateusBrowser->append("DSP烧写已完成，跳转至新应用程序！");
         }
         if(TempMsg.message.data[7]==0x03)
         {
            ui->StateusBrowser->append("无应用程序更新，跳转至应用程序！");
         }

     }

}

//连接按键按下
void MainWindow::on_ConnectpushButton_clicked()
{
    static int flag=1;
  if(flag==1)
  {
      ui->ConnectpushButton->setStyleSheet("background:rgb(0,255,0)");
      ui->ConnectpushButton->setText("断开");
      UdpConnectInit();
      flag=0;
  }
  else
  {
       receiver->close();
       ui->ConnectpushButton->setStyleSheet("default");
       ui->ConnectpushButton->setText("连接");
       flag=1;
  }

}

//发送按键按下
void MainWindow::on_pushButton_5_clicked()
{
  tarIp=ui->TarIPlineEdit->text();
  tarPort=ui->TarPortlineEdit->text().toUInt();
  QByteArray data = ui->SendlineEdit->text().toUtf8();
  QByteArray data1=data1.fromHex(data);
  sender->writeDatagram(data1, data1.size(),  QHostAddress(tarIp), tarPort);
//  receiver->writeDatagram();
}


//hex格式数据转为str
QString MainWindow::hex2Str(unsigned char *in, int len)
{
    QString s;
    for(int i=0;i<len;i++)
    {
        s+=QString("%1").arg(in[i]&0xFF,2,16,QLatin1Char('0')).toUpper();
        s.append(" ");
    }
    return s;
}

//清除键
void MainWindow::on_ClearButton_clicked()
{
  ui->RcvtableView->clearSpans();
   ui->StateusBrowser->clear();
}

//发送8个字节数据
void  MainWindow::SendData(QByteArray data,uint8_t len)
{
    QByteArray dataSend;
    uint32_t dataid=ui->IDPortlineEdit->text().toUInt();
    dataSend.append(len);
    dataSend.append(dataid>>24&0xFF);
    dataSend.append(dataid>>16&0xFF);
    dataSend.append(dataid>>8&0xFF);
    dataSend.append(dataid&0xFF);
    dataSend.append(data);

    tarIp=ui->TarIPlineEdit->text();
    tarPort=ui->TarPortlineEdit->text().toUInt();

    sender->writeDatagram(dataSend,dataSend.size(),QHostAddress(tarIp), tarPort);
}


//DSP连接按下
void MainWindow::on_DSPConnectButton_clicked()
{

    dspConnectTimer->start(1000);

}


//发送时间中断
void MainWindow::timerDspConnectSlot()
{
    static int i=0;
    i++;
    QByteArray data;
    data.append(5,0);
    data.append(0x66);
    data.append(0xCC);
    data.append(0x01);
    SendData(data,8);
    if(i==10)
    {
        i=0;
        dspConnectTimer->stop();
        if(dspConnectFlag==0)
        {
            ui->StateusBrowser->append("DSP未连接");
        }
    }
}


//读取hex文件并储存
void MainWindow::on_HexSendButton_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,tr("select hex file"),"./",tr("hex file(*.hex)"));
    if(fileName.isEmpty())
     {
          QMessageBox msg;
          msg.critical(this,tr("Error"),tr("打开文件发生错误"));
          return;
     }
    else
    {
        QFileInfo *fileinfo=new QFileInfo(fileName);
        QFile *file=new QFile;
        file->setFileName(fileinfo->filePath());
        if(file->open(QIODevice::ReadOnly|QIODevice::Text))
        {

            qDebug()<<fileinfo->size();
//            HexData.end()=HexData.begin();
            while(file->pos()<fileinfo->size())
            {
              QByteArray temp=file->readLine();
            //  qDebug()<<temp;
              HexData.append(temp);
            }
            file->close();
        }
         qDebug()<<"*********************"<<endl;
        for(int i=0;i<HexData.size();i++)
        {
           HexData[i].remove(0,1);
           HexData[i].remove(HexData[i].size()-1,1);
           qDebug()<<HexData[i];
        }
  }
   /*
    for(int j=0;j<HexData.size();j++)
    {
      HexdataArray.push_back(HexData[j]);
    }
       HexData.clear();
       SendBuf=QByteArray::fromHex(HexdataArray); 
       sendtimer->start(20);
     */
     sendtimer->start(100);
}

/*
//定时发送文件每一行 2021.5.20
void MainWindow::timerSendSlot()
{
    static int i=0;
    QByteArray tempBuf2;
    if(i<=SendBuf.size()-8)
    {
        tempBuf2.append(SendBuf.begin()+i,8);
        SendData(tempBuf2,8);
        tempBuf2.resize(0);
        if(i==SendBuf.size()&&SendBuf.size()%8==0)
        {
            sendtimer->stop();
            HexdataArray.clear();
            ui->StateusBrowser->append("发送完成！");
        }
    }
    else
    {
        tempBuf2.append(SendBuf.begin()+i,SendBuf.size()%8);
        SendData(tempBuf2,SendBuf.size()%8);
         sendtimer->stop();
         ui->StateusBrowser->append("发送完成！");
    }
    i=i+8;
} */

void MainWindow::timerSendSlot()
{
    static int i=0;
    QByteArray tempBuf1,tempBuf2;
    tempBuf1=QByteArray::fromHex(HexData[i]);
    tempBuf1.prepend(0xAA);
    tempBuf1.prepend(0x55);
    tempBuf1.append(0x0d);
    tempBuf1.append(0x0a);
    for(int j=0;j<tempBuf1.size();j=j+8)
    {
      tempBuf2.append(tempBuf1.begin()+j,8);
      SendData(tempBuf2,8);
      tempBuf2.clear();
    }
    tempBuf1.clear();
    i++;
    ui->progressBar->setRange(0,HexData.size());
    ui->progressBar->setValue(i);
    if(i==HexData.size())
    {
        sendtimer->stop();
        ui->StateusBrowser->append("发送完成！");
        i=0;
        HexData.clear();
    }
}
