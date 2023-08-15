/********************************************************************************
** Form generated from reading UI file 'NewContacts.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCONTACTS_H
#define UI_NEWCONTACTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewContactsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NewContactsClass)
    {
        if (NewContactsClass->objectName().isEmpty())
            NewContactsClass->setObjectName(QString::fromUtf8("NewContactsClass"));
        NewContactsClass->resize(600, 400);
        menuBar = new QMenuBar(NewContactsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        NewContactsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NewContactsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        NewContactsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(NewContactsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        NewContactsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(NewContactsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        NewContactsClass->setStatusBar(statusBar);

        retranslateUi(NewContactsClass);

        QMetaObject::connectSlotsByName(NewContactsClass);
    } // setupUi

    void retranslateUi(QMainWindow *NewContactsClass)
    {
        NewContactsClass->setWindowTitle(QCoreApplication::translate("NewContactsClass", "NewContacts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewContactsClass: public Ui_NewContactsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCONTACTS_H
