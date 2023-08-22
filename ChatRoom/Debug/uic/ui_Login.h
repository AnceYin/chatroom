/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginClass
{
public:
    QWidget *centralwidget;
    QPushButton *loginButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLineEdit *usernameLineEdit;
    QSpacerItem *horizontalSpacer;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLineEdit *passwordLineEdit;
    QSpacerItem *horizontalSpacer_4;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *registerButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *forgetButton;
    QSpacerItem *horizontalSpacer_7;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_9;

    void setupUi(QMainWindow *LoginClass)
    {
        if (LoginClass->objectName().isEmpty())
            LoginClass->setObjectName(QString::fromUtf8("LoginClass"));
        LoginClass->resize(600, 400);
        centralwidget = new QWidget(LoginClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(80, 220, 441, 41));
        QFont font;
        font.setPointSize(18);
        loginButton->setFont(font);
        loginButton->setStyleSheet(QString::fromUtf8("background:rgb(33, 173, 250);\n"
"color:rgb(255, 255, 255)"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(-1, 60, 601, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(15);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        usernameLineEdit = new QLineEdit(horizontalLayoutWidget);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));

        horizontalLayout->addWidget(usernameLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 120, 601, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        passwordLineEdit = new QLineEdit(horizontalLayoutWidget_2);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passwordLineEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(1, 290, 601, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        registerButton = new QPushButton(horizontalLayoutWidget_3);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setFont(font1);
        registerButton->setStyleSheet(QString::fromUtf8("color:rgb(131, 131, 131);\n"
"background:rgb(255, 255, 255)"));

        horizontalLayout_3->addWidget(registerButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        forgetButton = new QPushButton(horizontalLayoutWidget_3);
        forgetButton->setObjectName(QString::fromUtf8("forgetButton"));
        forgetButton->setFont(font1);
        forgetButton->setStyleSheet(QString::fromUtf8("color:rgb(131, 131, 131);\n"
"background:rgb(255, 255, 255)"));

        horizontalLayout_3->addWidget(forgetButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        horizontalLayoutWidget_4 = new QWidget(centralwidget);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(-1, 20, 601, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        label_3 = new QLabel(horizontalLayoutWidget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(85, 170, 255)"));

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        LoginClass->setCentralWidget(centralwidget);

        retranslateUi(LoginClass);

        QMetaObject::connectSlotsByName(LoginClass);
    } // setupUi

    void retranslateUi(QMainWindow *LoginClass)
    {
        LoginClass->setWindowTitle(QCoreApplication::translate("LoginClass", "Login", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginClass", "\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("LoginClass", "\350\264\246\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("LoginClass", "\345\257\206\347\240\201\357\274\232", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginClass", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        forgetButton->setText(QCoreApplication::translate("LoginClass", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("LoginClass", "\346\254\242\344\271\220\350\201\212\345\244\251\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginClass: public Ui_LoginClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
