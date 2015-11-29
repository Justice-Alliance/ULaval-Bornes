/********************************************************************************
** Form generated from reading UI file 'bornefontaineinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORNEFONTAINEINTERFACE_H
#define UI_BORNEFONTAINEINTERFACE_H

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

class Ui_BorneFontaineInterfaceClass
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *id;
    QLabel *label_2;
    QComboBox *direction;
    QLabel *label_3;
    QLineEdit *nom;
    QLabel *label_4;
    QDoubleSpinBox *longitude;
    QLabel *label_5;
    QDoubleSpinBox *latitude;
    QLabel *label_6;
    QLineEdit *ville;
    QLabel *label_7;
    QLineEdit *arrondissement;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BorneFontaineInterfaceClass)
    {
        if (BorneFontaineInterfaceClass->objectName().isEmpty())
            BorneFontaineInterfaceClass->setObjectName(QString::fromUtf8("BorneFontaineInterfaceClass"));
        BorneFontaineInterfaceClass->resize(400, 278);
        verticalLayout = new QVBoxLayout(BorneFontaineInterfaceClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(BorneFontaineInterfaceClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        id = new QSpinBox(BorneFontaineInterfaceClass);
        id->setObjectName(QString::fromUtf8("id"));

        gridLayout->addWidget(id, 0, 1, 1, 1);

        label_2 = new QLabel(BorneFontaineInterfaceClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        direction = new QComboBox(BorneFontaineInterfaceClass);
        direction->setObjectName(QString::fromUtf8("direction"));

        gridLayout->addWidget(direction, 1, 1, 1, 1);

        label_3 = new QLabel(BorneFontaineInterfaceClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        nom = new QLineEdit(BorneFontaineInterfaceClass);
        nom->setObjectName(QString::fromUtf8("nom"));

        gridLayout->addWidget(nom, 2, 1, 1, 1);

        label_4 = new QLabel(BorneFontaineInterfaceClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        longitude = new QDoubleSpinBox(BorneFontaineInterfaceClass);
        longitude->setObjectName(QString::fromUtf8("longitude"));

        gridLayout->addWidget(longitude, 3, 1, 1, 1);

        label_5 = new QLabel(BorneFontaineInterfaceClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        latitude = new QDoubleSpinBox(BorneFontaineInterfaceClass);
        latitude->setObjectName(QString::fromUtf8("latitude"));

        gridLayout->addWidget(latitude, 4, 1, 1, 1);

        label_6 = new QLabel(BorneFontaineInterfaceClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        ville = new QLineEdit(BorneFontaineInterfaceClass);
        ville->setObjectName(QString::fromUtf8("ville"));

        gridLayout->addWidget(ville, 5, 1, 1, 1);

        label_7 = new QLabel(BorneFontaineInterfaceClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        arrondissement = new QLineEdit(BorneFontaineInterfaceClass);
        arrondissement->setObjectName(QString::fromUtf8("arrondissement"));

        gridLayout->addWidget(arrondissement, 6, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(BorneFontaineInterfaceClass);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(BorneFontaineInterfaceClass);

        QMetaObject::connectSlotsByName(BorneFontaineInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *BorneFontaineInterfaceClass)
    {
        BorneFontaineInterfaceClass->setWindowTitle(QApplication::translate("BorneFontaineInterfaceClass", "BorneFontaineInterface", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BorneFontaineInterfaceClass", "Id", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BorneFontaineInterfaceClass", "Direction", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BorneFontaineInterfaceClass", "Nom", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BorneFontaineInterfaceClass", "Longitude", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BorneFontaineInterfaceClass", "Latitude", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BorneFontaineInterfaceClass", "Ville", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("BorneFontaineInterfaceClass", "Arrondissement", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BorneFontaineInterfaceClass: public Ui_BorneFontaineInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORNEFONTAINEINTERFACE_H
