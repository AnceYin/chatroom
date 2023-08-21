/********************************************************************************
** Form generated from reading UI file 'Register.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RegisterClass)
    {
        if (RegisterClass->objectName().isEmpty())
            RegisterClass->setObjectName(QString::fromUtf8("RegisterClass"));
        RegisterClass->resize(600, 400);
        menuBar = new QMenuBar(RegisterClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        RegisterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RegisterClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        RegisterClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(RegisterClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        RegisterClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RegisterClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RegisterClass->setStatusBar(statusBar);

        retranslateUi(RegisterClass);

        QMetaObject::connectSlotsByName(RegisterClass);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterClass)
    {
        RegisterClass->setWindowTitle(QCoreApplication::translate("RegisterClass", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterClass: public Ui_RegisterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
