/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *IPlineEdit;
    QLineEdit *PortlineEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *ConnectpushButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *IDPortlineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *DSPConnectButton;
    QPushButton *ClearButton;
    QPushButton *HexSendButton;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_6;
    QTextBrowser *StateusBrowser;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QTableView *RcvtableView;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *TarIPlineEdit;
    QLabel *label_5;
    QLineEdit *TarPortlineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *SendlineEdit;
    QPushButton *pushButton_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(615, 494);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 581, 441));
        verticalLayout_6 = new QVBoxLayout(widget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        IPlineEdit = new QLineEdit(widget);
        IPlineEdit->setObjectName(QString::fromUtf8("IPlineEdit"));

        verticalLayout_3->addWidget(IPlineEdit);

        PortlineEdit = new QLineEdit(widget);
        PortlineEdit->setObjectName(QString::fromUtf8("PortlineEdit"));

        verticalLayout_3->addWidget(PortlineEdit);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        ConnectpushButton = new QPushButton(widget);
        ConnectpushButton->setObjectName(QString::fromUtf8("ConnectpushButton"));

        horizontalLayout_3->addWidget(ConnectpushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        IDPortlineEdit = new QLineEdit(widget);
        IDPortlineEdit->setObjectName(QString::fromUtf8("IDPortlineEdit"));

        horizontalLayout_4->addWidget(IDPortlineEdit);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        DSPConnectButton = new QPushButton(widget);
        DSPConnectButton->setObjectName(QString::fromUtf8("DSPConnectButton"));

        horizontalLayout_2->addWidget(DSPConnectButton);

        ClearButton = new QPushButton(widget);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));

        horizontalLayout_2->addWidget(ClearButton);

        HexSendButton = new QPushButton(widget);
        HexSendButton->setObjectName(QString::fromUtf8("HexSendButton"));

        horizontalLayout_2->addWidget(HexSendButton);


        verticalLayout_5->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_6 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        StateusBrowser = new QTextBrowser(widget);
        StateusBrowser->setObjectName(QString::fromUtf8("StateusBrowser"));

        horizontalLayout_7->addWidget(StateusBrowser);

        horizontalSpacer_5 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_5->addLayout(verticalLayout);


        horizontalLayout_9->addLayout(verticalLayout_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        RcvtableView = new QTableView(widget);
        RcvtableView->setObjectName(QString::fromUtf8("RcvtableView"));

        verticalLayout_2->addWidget(RcvtableView);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        TarIPlineEdit = new QLineEdit(widget);
        TarIPlineEdit->setObjectName(QString::fromUtf8("TarIPlineEdit"));

        horizontalLayout_5->addWidget(TarIPlineEdit);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        TarPortlineEdit = new QLineEdit(widget);
        TarPortlineEdit->setObjectName(QString::fromUtf8("TarPortlineEdit"));

        horizontalLayout_5->addWidget(TarPortlineEdit);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        SendlineEdit = new QLineEdit(widget);
        SendlineEdit->setObjectName(QString::fromUtf8("SendlineEdit"));

        horizontalLayout_6->addWidget(SendlineEdit);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_6->addWidget(pushButton_5);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout_9->addLayout(verticalLayout_2);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayout_8->addWidget(progressBar);


        verticalLayout_6->addLayout(horizontalLayout_8);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 615, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\234\254\345\234\260IP\357\274\232", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\234\254\345\234\260\347\253\257\345\217\243\357\274\232", nullptr));
        ConnectpushButton->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "ID\345\217\267\357\274\232", nullptr));
        DSPConnectButton->setText(QApplication::translate("MainWindow", "DSP\350\277\236\346\216\245", nullptr));
        ClearButton->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", nullptr));
        HexSendButton->setText(QApplication::translate("MainWindow", "HEX\346\226\207\344\273\266\345\217\221\351\200\201", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\347\233\256\346\240\207IP\357\274\232", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\347\233\256\346\240\207\347\253\257\345\217\243\357\274\232", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\350\277\233\345\272\246\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
