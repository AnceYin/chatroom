/********************************************************************************
** Form generated from reading UI file 'Profile.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_H
#define UI_PROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProfileClass)
    {
        if (ProfileClass->objectName().isEmpty())
            ProfileClass->setObjectName(QString::fromUtf8("ProfileClass"));
        ProfileClass->resize(600, 400);
        menuBar = new QMenuBar(ProfileClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ProfileClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProfileClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ProfileClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ProfileClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ProfileClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ProfileClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ProfileClass->setStatusBar(statusBar);

        retranslateUi(ProfileClass);

        QMetaObject::connectSlotsByName(ProfileClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProfileClass)
    {
        ProfileClass->setWindowTitle(QCoreApplication::translate("ProfileClass", "Profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfileClass: public Ui_ProfileClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_H
