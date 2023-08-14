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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterClass
{
public:
    QWidget *centralWidget;
    QPushButton *Register;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RegisterClass)
    {
        if (RegisterClass->objectName().isEmpty())
            RegisterClass->setObjectName(QString::fromUtf8("RegisterClass"));
        RegisterClass->resize(600, 400);
        centralWidget = new QWidget(RegisterClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Register = new QPushButton(centralWidget);
        Register->setObjectName(QString::fromUtf8("Register"));
        Register->setGeometry(QRect(270, 230, 40, 40));
        Register->setMinimumSize(QSize(40, 40));
        Register->setMaximumSize(QSize(40, 40));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 230, 113, 40));
        lineEdit->setMinimumSize(QSize(0, 40));
        lineEdit->setMaximumSize(QSize(16777215, 40));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 170, 171, 40));
        lineEdit_2->setMinimumSize(QSize(0, 40));
        lineEdit_2->setMaximumSize(QSize(16777215, 40));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 140, 72, 15));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(500, 10, 72, 15));
        RegisterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RegisterClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        RegisterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RegisterClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        RegisterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RegisterClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RegisterClass->setStatusBar(statusBar);

        retranslateUi(RegisterClass);

        QMetaObject::connectSlotsByName(RegisterClass);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterClass)
    {
        RegisterClass->setWindowTitle(QCoreApplication::translate("RegisterClass", "Register", nullptr));
        Register->setText(QCoreApplication::translate("RegisterClass", "Ok", nullptr));
        label->setText(QCoreApplication::translate("RegisterClass", "BChat", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterClass", "Sign in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterClass: public Ui_RegisterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
