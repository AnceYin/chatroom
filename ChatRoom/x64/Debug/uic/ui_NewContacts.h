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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewContactsClass
{
public:
    QWidget *centralWidget;
    QPushButton *Return;

    void setupUi(QMainWindow *NewContactsClass)
    {
        if (NewContactsClass->objectName().isEmpty())
            NewContactsClass->setObjectName(QString::fromUtf8("NewContactsClass"));
        NewContactsClass->resize(750, 460);
        NewContactsClass->setMinimumSize(QSize(750, 460));
        NewContactsClass->setMaximumSize(QSize(750, 460));
        centralWidget = new QWidget(NewContactsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Return = new QPushButton(centralWidget);
        Return->setObjectName(QString::fromUtf8("Return"));
        Return->setGeometry(QRect(10, 10, 121, 51));
        Return->setMinimumSize(QSize(70, 40));
        Return->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton::icon {\n"
"    margin-left: 0px;  // \345\260\206\345\233\276\346\240\207\347\232\204\345\267\246\350\276\271\350\267\235\350\256\276\344\270\2720\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../\345\233\276\347\211\207/\350\277\224\345\233\236\345\217\214\347\256\255\345\244\264.png"), QSize(), QIcon::Normal, QIcon::Off);
        Return->setIcon(icon);
        Return->setIconSize(QSize(50, 50));
        NewContactsClass->setCentralWidget(centralWidget);

        retranslateUi(NewContactsClass);

        QMetaObject::connectSlotsByName(NewContactsClass);
    } // setupUi

    void retranslateUi(QMainWindow *NewContactsClass)
    {
        NewContactsClass->setWindowTitle(QCoreApplication::translate("NewContactsClass", "NewContacts", nullptr));
        Return->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewContactsClass: public Ui_NewContactsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCONTACTS_H
