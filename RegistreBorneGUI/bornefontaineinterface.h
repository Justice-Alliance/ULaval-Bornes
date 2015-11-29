#ifndef BORNEFONTAINEINTERFACE_H
#define BORNEFONTAINEINTERFACE_H

#include <QtGui/QDialog>
#include "ui_bornefontaineinterface.h"
#include "BorneFontaine.h"

class BorneFontaineInterface : public QDialog
{
    Q_OBJECT

public:
    BorneFontaineInterface(QWidget *parent = 0);
    ~BorneFontaineInterface();
    tp::BorneFontaine* creerBorne() const;
    int reqId() const;
    QString reqDirection() const;
    QString reqNom() const;
    double reqLongitude() const;
    double reqLatitude() const;
    QString reqVille() const;
    QString reqArrondissement() const;

private slots:
	void validerBorne();

private:
    Ui::BorneFontaineInterfaceClass ui;
};

#endif // BORNEFONTAINEINTERFACE_H
