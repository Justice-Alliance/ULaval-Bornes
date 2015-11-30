#include <QMessageBox>
#include "bornestationnementinterface.h"

BorneStationnementInterface::BorneStationnementInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle("Formulaire d'ajout d'une borne de stationnement");

	QStringList directions;
	directions << "Nord" << "Ouest" << "Sud" << "Est";
	ui.direction->addItems(directions);

	QStringList types;
	types << "stationnement" << "paiement";
	ui.type->addItems(types);

	ui.coteRue->addItems(directions);

	QWidget::connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(validerBorne()));
	QWidget::connect(ui.buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

}

BorneStationnementInterface::~BorneStationnementInterface()
{
}


tp::BorneStationnement* BorneStationnementInterface::creerBorne() const
{
	return new tp::BorneStationnement(reqId(), reqDirection().toStdString(),
		reqNom().toStdString(), reqLongitude(), reqLatitude(),
		reqType().toStdString(), reqLectureMetrique(), reqSegmentRue(),
		reqNumBorne().toStdString(), reqCoteRue().toStdString());
}

void BorneStationnementInterface::validerBorne()
{
	if (reqNom().isEmpty())
	{
		QMessageBox::information(this, "Erreur !",
			QString("Le nom ne doit pas etre vide"));
		return;
	}
	if (reqLectureMetrique() <= 0.0)
	{
		QMessageBox::information(this, "Erreur !",
			QString("La lecture metrique doit etre > 0"));
		return;
	}
	if (reqSegmentRue() <= 0)
	{
		QMessageBox::information(this, "Erreur !",
			QString("Le segment rue doit etre > 0"));
		return;
	}
	if (reqNumBorne().isEmpty())
	{
		QMessageBox::information(this, "Erreur !",
			QString("Le numero de la borne ne doit pas etre vide"));
		return;
	}

	accept();
}


int BorneStationnementInterface::reqId() const
{
	return ui.id->value();
}

QString BorneStationnementInterface::reqDirection() const
{
	return ui.direction->currentText();
}

QString BorneStationnementInterface::reqNom() const
{
	return ui.nom->text();
}

double BorneStationnementInterface::reqLongitude() const
{
	return ui.longitude->value();
}

double BorneStationnementInterface::reqLatitude() const
{
	return ui.latitude->value();
}

QString BorneStationnementInterface::reqType() const
{
	return ui.type->currentText();
}

double BorneStationnementInterface::reqLectureMetrique() const
{
	return ui.lectureMetrique->value();
}

int BorneStationnementInterface::reqSegmentRue() const
{
	return ui.segmentRue->value();
}

QString BorneStationnementInterface::reqNumBorne() const
{
	return ui.numBorne->text();
}

QString BorneStationnementInterface::reqCoteRue() const
{
	return ui.coteRue->currentText();
}

