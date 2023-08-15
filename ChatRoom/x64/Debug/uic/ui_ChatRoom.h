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
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatRoomClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChatRoomClass)
    {
        if (ChatRoomClass->objectName().isEmpty())
            ChatRoomClass->setObjectName(QString::fromUtf8("ChatRoomClass"));
        ChatRoomClass->resize(600, 400);
        menuBar = new QMenuBar(ChatRoomClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ChatRoomClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChatRoomClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ChatRoomClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ChatRoomClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ChatRoomClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ChatRoomClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ChatRoomClass->setStatusBar(statusBar);

        retranslateUi(ChatRoomClass);

        QMetaObject::connectSlotsByName(ChatRoomClass);
    } // setupUi

    void retranslateUi(QMainWindow *ChatRoomClass)
    {
        ChatRoomClass->setWindowTitle(QCoreApplication::translate("ChatRoomClass", "ChatRoom", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatRoomClass: public Ui_ChatRoomClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOM_H
