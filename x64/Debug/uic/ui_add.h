/********************************************************************************
** Form generated from reading UI file 'add.ui'
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

class Ui_addClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *addClass)
    {
        if (addClass->objectName().isEmpty())
            addClass->setObjectName(QString::fromUtf8("addClass"));
        addClass->resize(600, 400);
        menuBar = new QMenuBar(addClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        addClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(addClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        addClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(addClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        addClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(addClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        addClass->setStatusBar(statusBar);

        retranslateUi(addClass);

        QMetaObject::connectSlotsByName(addClass);
    } // setupUi

    void retranslateUi(QMainWindow *addClass)
    {
        addClass->setWindowTitle(QCoreApplication::translate("addClass", "add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addClass: public Ui_addClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
