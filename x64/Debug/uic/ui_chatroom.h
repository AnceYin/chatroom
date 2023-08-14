/********************************************************************************
** Form generated from reading UI file 'chatroom.ui'
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

class Ui_chatroomClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *chatroomClass)
    {
        if (chatroomClass->objectName().isEmpty())
            chatroomClass->setObjectName(QString::fromUtf8("chatroomClass"));
        chatroomClass->resize(600, 400);
        centralWidget = new QWidget(chatroomClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        chatroomClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(chatroomClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        chatroomClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(chatroomClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        chatroomClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(chatroomClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        chatroomClass->setStatusBar(statusBar);

        retranslateUi(chatroomClass);

        QMetaObject::connectSlotsByName(chatroomClass);
    } // setupUi

    void retranslateUi(QMainWindow *chatroomClass)
    {
        chatroomClass->setWindowTitle(QCoreApplication::translate("chatroomClass", "chatroom", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatroomClass: public Ui_chatroomClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOM_H
