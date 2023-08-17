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
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatRoomClass
{
public:
    QWidget *centralWidget;
    QListView *listView;
    QTextEdit *Message;
    QPushButton *Send;
    QPushButton *Serach;
    QLineEdit *Serach_LineEdit;
    QLabel *label;
    QPushButton *Log_out;

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
        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(140, 50, 601, 341));
        Message = new QTextEdit(centralWidget);
        Message->setObjectName(QString::fromUtf8("Message"));
        Message->setGeometry(QRect(140, 400, 481, 41));
        Send = new QPushButton(centralWidget);
        Send->setObjectName(QString::fromUtf8("Send"));
        Send->setGeometry(QRect(640, 400, 101, 41));
        Serach = new QPushButton(centralWidget);
        Serach->setObjectName(QString::fromUtf8("Serach"));
        Serach->setGeometry(QRect(0, 10, 31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../\345\233\276\347\211\207/\346\220\234\347\264\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        Serach->setIcon(icon);
        Serach_LineEdit = new QLineEdit(centralWidget);
        Serach_LineEdit->setObjectName(QString::fromUtf8("Serach_LineEdit"));
        Serach_LineEdit->setGeometry(QRect(40, 10, 91, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 10, 541, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        label->setFont(font);
        Log_out = new QPushButton(centralWidget);
        Log_out->setObjectName(QString::fromUtf8("Log_out"));
        Log_out->setGeometry(QRect(10, 400, 111, 41));
        Log_out->setFont(font);
        Log_out->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: left;\n"
"}"));
        ChatRoomClass->setCentralWidget(centralWidget);

        retranslateUi(ChatRoomClass);

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
    } // retranslateUi

};

namespace Ui {
    class ChatRoomClass: public Ui_ChatRoomClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOM_H
