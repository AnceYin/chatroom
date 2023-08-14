/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginClass
{
public:
    QWidget *centralWidget;
    QPushButton *login;
    QLabel *Sign_up;
    QLabel *Foget_password;
    QLabel *label_3;
    QLineEdit *username;
    QLineEdit *password;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *loginClass)
    {
        if (loginClass->objectName().isEmpty())
            loginClass->setObjectName(QString::fromUtf8("loginClass"));
        loginClass->resize(584, 382);
        loginClass->setMaximumSize(QSize(16777215, 16777215));
        centralWidget = new QWidget(loginClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        login = new QPushButton(centralWidget);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(290, 200, 40, 40));
        login->setMinimumSize(QSize(40, 40));
        login->setMaximumSize(QSize(40, 40));
        Sign_up = new QLabel(centralWidget);
        Sign_up->setObjectName(QString::fromUtf8("Sign_up"));
        Sign_up->setGeometry(QRect(480, 20, 72, 15));
        Foget_password = new QLabel(centralWidget);
        Foget_password->setObjectName(QString::fromUtf8("Foget_password"));
        Foget_password->setGeometry(QRect(440, 320, 141, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 120, 72, 15));
        username = new QLineEdit(centralWidget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(170, 150, 161, 40));
        username->setMinimumSize(QSize(0, 40));
        username->setMaximumSize(QSize(16777215, 40));
        password = new QLineEdit(centralWidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(170, 200, 113, 40));
        password->setMinimumSize(QSize(0, 40));
        password->setMaximumSize(QSize(16777215, 40));
        loginClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(loginClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        loginClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(loginClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setMinimumSize(QSize(0, 0));
        statusBar->setMaximumSize(QSize(16777215, 16777215));
        loginClass->setStatusBar(statusBar);

        retranslateUi(loginClass);
        QObject::connect(Sign_up, SIGNAL(linkActivated(QString)), loginClass, SLOT(onLinkActivated()));
        QObject::connect(login, SIGNAL(clicked()), loginClass, SLOT(PushButtonClicked()));

        QMetaObject::connectSlotsByName(loginClass);
    } // setupUi

    void retranslateUi(QMainWindow *loginClass)
    {
        loginClass->setWindowTitle(QCoreApplication::translate("loginClass", "login", nullptr));
        login->setText(QCoreApplication::translate("loginClass", "Ok", nullptr));
        Sign_up->setText(QCoreApplication::translate("loginClass", "Sign up", nullptr));
        Foget_password->setText(QCoreApplication::translate("loginClass", "Forget password?", nullptr));
        label_3->setText(QCoreApplication::translate("loginClass", "BChat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginClass: public Ui_loginClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
