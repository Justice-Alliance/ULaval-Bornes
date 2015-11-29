/********************************************************************************
** Form generated from reading UI file 'registreborne.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTREBORNE_H
#define UI_REGISTREBORNE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistreBorneClass
{
public:
    QWidget *centralwidget;
    QPushButton *btnQuit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegistreBorneClass)
    {
        if (RegistreBorneClass->objectName().isEmpty())
            RegistreBorneClass->setObjectName(QString::fromUtf8("RegistreBorneClass"));
        RegistreBorneClass->resize(800, 600);
        centralwidget = new QWidget(RegistreBorneClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnQuit = new QPushButton(centralwidget);
        btnQuit->setObjectName(QString::fromUtf8("btnQuit"));
        btnQuit->setGeometry(QRect(430, 240, 88, 27));
        RegistreBorneClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegistreBorneClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        RegistreBorneClass->setMenuBar(menubar);
        statusbar = new QStatusBar(RegistreBorneClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RegistreBorneClass->setStatusBar(statusbar);

        retranslateUi(RegistreBorneClass);

        QMetaObject::connectSlotsByName(RegistreBorneClass);
    } // setupUi

    void retranslateUi(QMainWindow *RegistreBorneClass)
    {
        RegistreBorneClass->setWindowTitle(QApplication::translate("RegistreBorneClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        btnQuit->setText(QApplication::translate("RegistreBorneClass", "Quitter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RegistreBorneClass: public Ui_RegistreBorneClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTREBORNE_H
