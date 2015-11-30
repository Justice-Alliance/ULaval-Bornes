#ifndef BORNESTATIONNEMENTINTERFACE_H
#define BORNESTATIONNEMENTINTERFACE_H

#include <QtGui/QDialog>
#include "ui_bornestationnementinterface.h"
#include "BorneStationnement.h"

class BorneStationnementInterface : public QDialog
{
    Q_OBJECT

public:
    BorneStationnementInterface(QWidget *parent = 0);
    ~BorneStationnementInterface();
    tp::BorneStationnement* creerBorne() const;
    int reqId() const;
    QString reqDirection() const;
    QString reqNom() const;
    double reqLongitude() const;
    double reqLatitude() const;
    QString reqType() const;
    double reqLectureMetrique() const;
    int reqSegmentRue() const;
    QString reqNumBorne() const;
    QString reqCoteRue() const;

private slots:
	void validerBorne();

private:
    Ui::BorneStationnementInterfaceClass ui;
};

#endif // BORNESTATIONNEMENTINTERFACE_H
