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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_2;
    QPushButton *create;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AddClass)
    {
        if (AddClass->objectName().isEmpty())
            AddClass->setObjectName(QString::fromUtf8("AddClass"));
        AddClass->resize(350, 500);
        AddClass->setMinimumSize(QSize(350, 500));
        AddClass->setMaximumSize(QSize(350, 500));
        centralWidget = new QWidget(AddClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(225, 371));
        widget->setMaximumSize(QSize(231, 371));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(200, 200));
        QFont font;
        font.setPointSize(60);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(200, 200, 198);\n"
"border-radius:100px;\n"
"border:4px groove gray;\n"
"border-style:outset;\n"
"}"));
        pushButton->setIconSize(QSize(100, 100));

        verticalLayout->addWidget(pushButton);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(15);
        font1.setItalic(true);
        lineEdit->setFont(font1);
        lineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lineEdit);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        create = new QPushButton(widget);
        create->setObjectName(QString::fromUtf8("create"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Cambria"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        create->setFont(font2);

        verticalLayout->addWidget(create);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        horizontalLayout->addWidget(widget);

        horizontalSpacer_2 = new QSpacerItem(44, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        AddClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AddClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 350, 22));
        AddClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AddClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AddClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AddClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AddClass->setStatusBar(statusBar);

        retranslateUi(AddClass);

        QMetaObject::connectSlotsByName(AddClass);
    } // setupUi

    void retranslateUi(QMainWindow *AddClass)
    {
        AddClass->setWindowTitle(QCoreApplication::translate("AddClass", "Add", nullptr));
        pushButton->setText(QCoreApplication::translate("AddClass", "+", nullptr));
        create->setText(QCoreApplication::translate("AddClass", "creating\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddClass: public Ui_AddClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
