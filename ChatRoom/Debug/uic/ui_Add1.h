/********************************************************************************
** Form generated from reading UI file 'Add1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD1_H
#define UI_ADD1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreatGroupClass
{
public:
    QWidget *centralWidget;
    QWidget *widget_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QListWidget *list_contact;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CreatGroupClass)
    {
        if (CreatGroupClass->objectName().isEmpty())
            CreatGroupClass->setObjectName(QString::fromUtf8("CreatGroupClass"));
        CreatGroupClass->setEnabled(true);
        CreatGroupClass->resize(750, 460);
        CreatGroupClass->setMinimumSize(QSize(750, 460));
        CreatGroupClass->setMaximumSize(QSize(750, 460));
        centralWidget = new QWidget(CreatGroupClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(10, 0, 731, 401));
        widget = new QWidget(widget_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-10, 0, 221, 401));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        list_contact = new QListWidget(widget);
        QBrush brush(QColor(170, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        QFont font;
        font.setPointSize(13);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(list_contact);
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setBackground(brush);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(list_contact);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem1->setFont(font);
        QBrush brush1(QColor(200, 200, 199, 255));
        brush1.setStyle(Qt::SolidPattern);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(list_contact);
        __qlistwidgetitem2->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem2->setFont(font);
        __qlistwidgetitem2->setBackground(brush1);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(list_contact);
        __qlistwidgetitem3->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem3->setFont(font);
        list_contact->setObjectName(QString::fromUtf8("list_contact"));
        list_contact->setEnabled(true);
        list_contact->setSizeIncrement(QSize(10, 10));
        list_contact->setEditTriggers(QAbstractItemView::SelectedClicked);

        verticalLayout->addWidget(list_contact);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(200, 0, 531, 441));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 105, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 50));
        label->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setLineWidth(1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 104, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QFont font2;
        font2.setPointSize(14);
        font2.setItalic(true);
        lineEdit->setFont(font2);
        lineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lineEdit);

        verticalSpacer_3 = new QSpacerItem(20, 105, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        CreatGroupClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CreatGroupClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 750, 22));
        CreatGroupClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CreatGroupClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CreatGroupClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CreatGroupClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CreatGroupClass->setStatusBar(statusBar);

        retranslateUi(CreatGroupClass);

        QMetaObject::connectSlotsByName(CreatGroupClass);
    } // setupUi

    void retranslateUi(QMainWindow *CreatGroupClass)
    {
        CreatGroupClass->setWindowTitle(QCoreApplication::translate("CreatGroupClass", "CreatGroup", nullptr));

        const bool __sortingEnabled = list_contact->isSortingEnabled();
        list_contact->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = list_contact->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("CreatGroupClass", "<<", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = list_contact->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("CreatGroupClass", "New Contact", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = list_contact->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("CreatGroupClass", "Join a Group", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = list_contact->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("CreatGroupClass", "Create a Group", nullptr));
        list_contact->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("CreatGroupClass", "New Contact", nullptr));
        lineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreatGroupClass: public Ui_CreatGroupClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD1_H
