/********************************************************************************
** Form generated from reading UI file 'creat_group.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREAT_GROUP_H
#define UI_CREAT_GROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_creat_groupClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *creat_groupClass)
    {
        if (creat_groupClass->objectName().isEmpty())
            creat_groupClass->setObjectName(QString::fromUtf8("creat_groupClass"));
        creat_groupClass->resize(600, 400);
        menuBar = new QMenuBar(creat_groupClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        creat_groupClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(creat_groupClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        creat_groupClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(creat_groupClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        creat_groupClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(creat_groupClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        creat_groupClass->setStatusBar(statusBar);

        retranslateUi(creat_groupClass);

        QMetaObject::connectSlotsByName(creat_groupClass);
    } // setupUi

    void retranslateUi(QMainWindow *creat_groupClass)
    {
        creat_groupClass->setWindowTitle(QCoreApplication::translate("creat_groupClass", "creat_group", nullptr));
    } // retranslateUi

};

namespace Ui {
    class creat_groupClass: public Ui_creat_groupClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREAT_GROUP_H
