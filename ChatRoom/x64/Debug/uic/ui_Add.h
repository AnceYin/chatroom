/********************************************************************************
** Form generated from reading UI file 'Add.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_H
#define UI_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AddClass)
    {
        if (AddClass->objectName().isEmpty())
            AddClass->setObjectName(QString::fromUtf8("AddClass"));
        AddClass->resize(600, 400);
        menuBar = new QMenuBar(AddClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        AddClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AddClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AddClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(AddClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        AddClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(AddClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AddClass->setStatusBar(statusBar);

        retranslateUi(AddClass);

        QMetaObject::connectSlotsByName(AddClass);
    } // setupUi

    void retranslateUi(QMainWindow *AddClass)
    {
        AddClass->setWindowTitle(QCoreApplication::translate("AddClass", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddClass: public Ui_AddClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
