/********************************************************************************
** Form generated from reading UI file 'registrebornegui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTREBORNEGUI_H
#define UI_REGISTREBORNEGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistreBorneGUIClass
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *borneTable;
    QVBoxLayout *verticalLayout;
    QPushButton *addFontaineBtn;
    QPushButton *addStationnementBtn;
    QPushButton *deleteBtn;
    QPushButton *quitBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegistreBorneGUIClass)
    {
        if (RegistreBorneGUIClass->objectName().isEmpty())
            RegistreBorneGUIClass->setObjectName(QString::fromUtf8("RegistreBorneGUIClass"));
        RegistreBorneGUIClass->resize(592, 309);
        centralwidget = new QWidget(RegistreBorneGUIClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 30, 502, 194));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        borneTable = new QTableWidget(layoutWidget);
        borneTable->setObjectName(QString::fromUtf8("borneTable"));

        horizontalLayout->addWidget(borneTable);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addFontaineBtn = new QPushButton(layoutWidget);
        addFontaineBtn->setObjectName(QString::fromUtf8("addFontaineBtn"));

        verticalLayout->addWidget(addFontaineBtn);

        addStationnementBtn = new QPushButton(layoutWidget);
        addStationnementBtn->setObjectName(QString::fromUtf8("addStationnementBtn"));

        verticalLayout->addWidget(addStationnementBtn);

        deleteBtn = new QPushButton(layoutWidget);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));

        verticalLayout->addWidget(deleteBtn);

        quitBtn = new QPushButton(layoutWidget);
        quitBtn->setObjectName(QString::fromUtf8("quitBtn"));

        verticalLayout->addWidget(quitBtn);


        horizontalLayout->addLayout(verticalLayout);

        RegistreBorneGUIClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegistreBorneGUIClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 592, 27));
        RegistreBorneGUIClass->setMenuBar(menubar);
        statusbar = new QStatusBar(RegistreBorneGUIClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RegistreBorneGUIClass->setStatusBar(statusbar);

        retranslateUi(RegistreBorneGUIClass);

        QMetaObject::connectSlotsByName(RegistreBorneGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *RegistreBorneGUIClass)
    {
        RegistreBorneGUIClass->setWindowTitle(QApplication::translate("RegistreBorneGUIClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        addFontaineBtn->setText(QApplication::translate("RegistreBorneGUIClass", "Ajouter une borne fontaine", 0, QApplication::UnicodeUTF8));
        addStationnementBtn->setText(QApplication::translate("RegistreBorneGUIClass", "Ajouter une borne de stationnement", 0, QApplication::UnicodeUTF8));
        deleteBtn->setText(QApplication::translate("RegistreBorneGUIClass", "Supprimer", 0, QApplication::UnicodeUTF8));
        quitBtn->setText(QApplication::translate("RegistreBorneGUIClass", "Quitter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RegistreBorneGUIClass: public Ui_RegistreBorneGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTREBORNEGUI_H
