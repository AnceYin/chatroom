/********************************************************************************
** Form generated from reading UI file 'ChatRoom.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOM_H
#define UI_CHATROOM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatRoomClass
{
public:
    QWidget *centralWidget;
    QTextEdit *Message;
    QPushButton *Send;
    QPushButton *Serach;
    QLineEdit *Serach_LineEdit;
    QLabel *label;
    QPushButton *Log_out;
    QScrollArea *scrollArea;
    QWidget *scrollArea_2;
    QListWidget *listWidget;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents;
    QListWidget *listWidget_MessageQueue;
    QPushButton *DeletePushButton;

    void setupUi(QMainWindow *ChatRoomClass)
    {
        if (ChatRoomClass->objectName().isEmpty())
            ChatRoomClass->setObjectName(QString::fromUtf8("ChatRoomClass"));
        ChatRoomClass->resize(750, 460);
        ChatRoomClass->setMinimumSize(QSize(750, 460));
        ChatRoomClass->setMaximumSize(QSize(750, 460));
        ChatRoomClass->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 10px; // \346\240\271\346\215\256\351\234\200\346\261\202\350\256\276\347\275\256\345\267\246\350\276\271\350\267\235\n"
"}\n"
"\n"
""));
        centralWidget = new QWidget(ChatRoomClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Message = new QTextEdit(centralWidget);
        Message->setObjectName(QString::fromUtf8("Message"));
        Message->setGeometry(QRect(140, 400, 491, 41));
        Send = new QPushButton(centralWidget);
        Send->setObjectName(QString::fromUtf8("Send"));
        Send->setGeometry(QRect(640, 400, 101, 41));
        Serach = new QPushButton(centralWidget);
        Serach->setObjectName(QString::fromUtf8("Serach"));
        Serach->setGeometry(QRect(0, 10, 31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/serach.png"), QSize(), QIcon::Normal, QIcon::Off);
        Serach->setIcon(icon);
        Serach_LineEdit = new QLineEdit(centralWidget);
        Serach_LineEdit->setObjectName(QString::fromUtf8("Serach_LineEdit"));
        Serach_LineEdit->setGeometry(QRect(40, 10, 91, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 10, 551, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        label->setFont(font);
        Log_out = new QPushButton(centralWidget);
        Log_out->setObjectName(QString::fromUtf8("Log_out"));
        Log_out->setGeometry(QRect(10, 400, 121, 41));
        Log_out->setFont(font);
        Log_out->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: left;\n"
"}"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(140, 50, 601, 341));
        scrollArea->setWidgetResizable(true);
        scrollArea_2 = new QWidget();
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(0, 0, 599, 339));
        listWidget = new QListWidget(scrollArea_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 601, 341));
        scrollArea->setWidget(scrollArea_2);
        scrollArea_3 = new QScrollArea(centralWidget);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setGeometry(QRect(10, 50, 121, 341));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 119, 339));
        listWidget_MessageQueue = new QListWidget(scrollAreaWidgetContents);
        listWidget_MessageQueue->setObjectName(QString::fromUtf8("listWidget_MessageQueue"));
        listWidget_MessageQueue->setGeometry(QRect(0, 0, 121, 341));
        scrollArea_3->setWidget(scrollAreaWidgetContents);
        DeletePushButton = new QPushButton(centralWidget);
        DeletePushButton->setObjectName(QString::fromUtf8("DeletePushButton"));
        DeletePushButton->setGeometry(QRect(620, 10, 121, 31));
        ChatRoomClass->setCentralWidget(centralWidget);

        retranslateUi(ChatRoomClass);
        QObject::connect(Send, SIGNAL(clicked()), ChatRoomClass, SLOT(SendPushButtonClicked()));
        QObject::connect(Log_out, SIGNAL(clicked()), ChatRoomClass, SLOT(LogOutPushButtonClicked()));
        QObject::connect(Serach, SIGNAL(clicked()), ChatRoomClass, SLOT(SerachPushButtonClicked()));

        QMetaObject::connectSlotsByName(ChatRoomClass);
    } // setupUi

    void retranslateUi(QMainWindow *ChatRoomClass)
    {
        ChatRoomClass->setWindowTitle(QCoreApplication::translate("ChatRoomClass", "ChatRoom", nullptr));
        Send->setText(QCoreApplication::translate("ChatRoomClass", "Send", nullptr));
        Serach->setText(QString());
        Serach_LineEdit->setText(QString());
        label->setText(QCoreApplication::translate("ChatRoomClass", "Name", nullptr));
        Log_out->setText(QCoreApplication::translate("ChatRoomClass", "Log out", nullptr));
        DeletePushButton->setText(QCoreApplication::translate("ChatRoomClass", "Delete The Group", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatRoomClass: public Ui_ChatRoomClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOM_H
