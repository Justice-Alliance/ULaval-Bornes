#include <QMessageBox>
#include "bornefontaineinterface.h"

BorneFontaineInterface::BorneFontaineInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle("Formulaire d'ajout d'une borne fontaine");

	QStringList directions;
	directions << "Nord" << "Ouest" << "Sud" << "Est";
	ui.direction->addItems(directions);

	QWidget::connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(validerBorne()));
	QWidget::connect(ui.buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

BorneFontaineInterface::~BorneFontaineInterface()
{
}

tp::BorneFontaine* BorneFontaineInterface::creerBorne() const
{
	return new tp::BorneFontaine(reqId(), reqDirection().toStdString(),
		reqNom().toStdString(), reqLongitude(), reqLatitude(),
		reqVille().toStdString(), reqArrondissement().toStdString());
}

void BorneFontaineInterface::validerBorne()
{
	if (reqNom().isEmpty())
	{
		QMessageBox::information(this, "Erreur !",
			QString("Le nom ne doit pas etre vide"));
		return;
	}
	if ("Québec" == reqVille() && reqArrondissement().isEmpty())
	{
		QMessageBox::information(this, "Erreur !",
			QString("L'arrondissement ne doit pas etre vide"));
		return;
	}
	if ("Québec" != reqVille() && !reqArrondissement().isEmpty())
	{
		QMessageBox::information(this, "Erreur !",
			QString("L'arrondissement doit etre vide"));
		return;
	}


	accept();
}

int BorneFontaineInterface::reqId() const
{
	return ui.id->value();
}

QString BorneFontaineInterface::reqDirection() const
{
	return ui.direction->currentText();
}

QString BorneFontaineInterface::reqNom() const
{
	return ui.nom->text();
}

double BorneFontaineInterface::reqLongitude() const
{
	return ui.longitude->value();
}

double BorneFontaineInterface::reqLatitude() const
{
	return ui.latitude->value();
}

QString BorneFontaineInterface::reqVille() const
{
	return ui.ville->text();
}

QString BorneFontaineInterface::reqArrondissement() const
{
	return ui.arrondissement->text();
}

