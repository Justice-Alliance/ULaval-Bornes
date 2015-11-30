/********************************************************************************
** Form generated from reading UI file 'bornestationnementinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORNESTATIONNEMENTINTERFACE_H
#define UI_BORNESTATIONNEMENTINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BorneStationnementInterfaceClass
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *id;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *nom;
    QLabel *label_4;
    QDoubleSpinBox *longitude;
    QLabel *label_5;
    QDoubleSpinBox *latitude;
    QLabel *label_6;
    QComboBox *type;
    QLabel *label_7;
    QDoubleSpinBox *lectureMetrique;
    QSpinBox *segmentRue;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *numBorne;
    QLabel *label_10;
    QComboBox *direction;
    QComboBox *coteRue;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BorneStationnementInterfaceClass)
    {
        if (BorneStationnementInterfaceClass->objectName().isEmpty())
            BorneStationnementInterfaceClass->setObjectName(QString::fromUtf8("BorneStationnementInterfaceClass"));
        BorneStationnementInterfaceClass->resize(408, 377);
        verticalLayout = new QVBoxLayout(BorneStationnementInterfaceClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(BorneStationnementInterfaceClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        id = new QSpinBox(BorneStationnementInterfaceClass);
        id->setObjectName(QString::fromUtf8("id"));

        gridLayout->addWidget(id, 0, 1, 1, 1);

        label_2 = new QLabel(BorneStationnementInterfaceClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(BorneStationnementInterfaceClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        nom = new QLineEdit(BorneStationnementInterfaceClass);
        nom->setObjectName(QString::fromUtf8("nom"));

        gridLayout->addWidget(nom, 2, 1, 1, 1);

        label_4 = new QLabel(BorneStationnementInterfaceClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        longitude = new QDoubleSpinBox(BorneStationnementInterfaceClass);
        longitude->setObjectName(QString::fromUtf8("longitude"));

        gridLayout->addWidget(longitude, 3, 1, 1, 1);

        label_5 = new QLabel(BorneStationnementInterfaceClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        latitude = new QDoubleSpinBox(BorneStationnementInterfaceClass);
        latitude->setObjectName(QString::fromUtf8("latitude"));

        gridLayout->addWidget(latitude, 4, 1, 1, 1);

        label_6 = new QLabel(BorneStationnementInterfaceClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        type = new QComboBox(BorneStationnementInterfaceClass);
        type->setObjectName(QString::fromUtf8("type"));

        gridLayout->addWidget(type, 5, 1, 1, 1);

        label_7 = new QLabel(BorneStationnementInterfaceClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 2, 1);

        lectureMetrique = new QDoubleSpinBox(BorneStationnementInterfaceClass);
        lectureMetrique->setObjectName(QString::fromUtf8("lectureMetrique"));

        gridLayout->addWidget(lectureMetrique, 6, 1, 1, 1);

        segmentRue = new QSpinBox(BorneStationnementInterfaceClass);
        segmentRue->setObjectName(QString::fromUtf8("segmentRue"));

        gridLayout->addWidget(segmentRue, 7, 1, 2, 1);

        label_8 = new QLabel(BorneStationnementInterfaceClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 8, 0, 1, 1);

        label_9 = new QLabel(BorneStationnementInterfaceClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 9, 0, 1, 1);

        numBorne = new QLineEdit(BorneStationnementInterfaceClass);
        numBorne->setObjectName(QString::fromUtf8("numBorne"));

        gridLayout->addWidget(numBorne, 9, 1, 1, 1);

        label_10 = new QLabel(BorneStationnementInterfaceClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 10, 0, 1, 1);

        direction = new QComboBox(BorneStationnementInterfaceClass);
        direction->setObjectName(QString::fromUtf8("direction"));

        gridLayout->addWidget(direction, 1, 1, 1, 1);

        coteRue = new QComboBox(BorneStationnementInterfaceClass);
        coteRue->setObjectName(QString::fromUtf8("coteRue"));

        gridLayout->addWidget(coteRue, 10, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(BorneStationnementInterfaceClass);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(BorneStationnementInterfaceClass);

        QMetaObject::connectSlotsByName(BorneStationnementInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *BorneStationnementInterfaceClass)
    {
        BorneStationnementInterfaceClass->setWindowTitle(QApplication::translate("BorneStationnementInterfaceClass", "BorneStationnementInterface", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BorneStationnementInterfaceClass", "Id", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BorneStationnementInterfaceClass", "Direction", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BorneStationnementInterfaceClass", "Nom", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BorneStationnementInterfaceClass", "Longitude", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BorneStationnementInterfaceClass", "Latitude", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BorneStationnementInterfaceClass", "Type", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("BorneStationnementInterfaceClass", "Lecture metrique", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("BorneStationnementInterfaceClass", "Segment rue", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("BorneStationnementInterfaceClass", "Num borne", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("BorneStationnementInterfaceClass", "Cote rue", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BorneStationnementInterfaceClass: public Ui_BorneStationnementInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORNESTATIONNEMENTINTERFACE_H
