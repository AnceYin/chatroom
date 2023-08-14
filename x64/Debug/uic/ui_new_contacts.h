/********************************************************************************
** Form generated from reading UI file 'new_contacts.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_CONTACTS_H
#define UI_NEW_CONTACTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_contactsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *new_contactsClass)
    {
        if (new_contactsClass->objectName().isEmpty())
            new_contactsClass->setObjectName(QString::fromUtf8("new_contactsClass"));
        new_contactsClass->resize(600, 400);
        menuBar = new QMenuBar(new_contactsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        new_contactsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(new_contactsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        new_contactsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(new_contactsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        new_contactsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(new_contactsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        new_contactsClass->setStatusBar(statusBar);

        retranslateUi(new_contactsClass);

        QMetaObject::connectSlotsByName(new_contactsClass);
    } // setupUi

    void retranslateUi(QMainWindow *new_contactsClass)
    {
        new_contactsClass->setWindowTitle(QCoreApplication::translate("new_contactsClass", "new_contacts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_contactsClass: public Ui_new_contactsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_CONTACTS_H
