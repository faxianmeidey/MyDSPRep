#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QUdpSocket>
#include<QStandardItemModel>
#include<QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#pragma pack(1)
struct Message
{
  uint8_t type;
  uint32_t msgid;
  uint8_t data[8];
};


union Msg
{
  uint8_t data[13];
  struct Message message;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void UdpConnectInit();
    void processPending();
    QList<QStandardItem*>AddRowRecv(union Msg msg);
    QString hex2Str(unsigned char *in, int len);
    void timerDspConnectSlot();
    void timerSendSlot();
    void SendData(QByteArray data,uint8_t len);

private slots:
    void on_ConnectpushButton_clicked();

    void on_pushButton_5_clicked();


    void on_ClearButton_clicked();

    void on_DSPConnectButton_clicked();

    void on_HexSendButton_clicked();

private:
    Ui::MainWindow *ui;
    QUdpSocket *receiver;
    QUdpSocket *sender;
    QStandardItemModel *theModel;
    union Msg TempMsg;
    QTimer *sendtimer;
    QTimer *dspConnectTimer;
    QString tarIp;
    uint16_t tarPort;
    int dspConnectFlag;
    QByteArrayList HexData;
   QByteArray HexdataArray;
   QByteArray SendBuf;
};
#endif // MAINWINDOW_H
