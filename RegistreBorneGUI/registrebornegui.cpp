#include <QMessageBox>
#include "registrebornegui.h"
#include "bornefontaineinterface.h"
#include "bornestationnementinterface.h"

using namespace std;
using namespace tp;

RegistreBorneGUI::RegistreBorneGUI(QWidget *parent)
    : QMainWindow(parent), registre("Registre V1")
{
	ui.setupUi(this);
	QStringList entete;
	entete << "Id" << "Nom topographique";
	ui.borneTable->setColumnCount(2);
	ui.borneTable->setHorizontalHeaderLabels(entete);
	setWindowTitle("Registre borne");


	QObject::connect(ui.addFontaineBtn, SIGNAL(pressed()),
		this, SLOT(afficheFontaineForm()));
	QObject::connect(ui.addStationnementBtn, SIGNAL(pressed()),
		this, SLOT(afficheStationnementForm()));
	QObject::connect(ui.deleteBtn, SIGNAL(pressed()),
		this, SLOT(supprimerBorne()));
	QObject::connect(ui.quitBtn, SIGNAL(pressed()), this, SLOT(close()));
}

RegistreBorneGUI::~RegistreBorneGUI()
{
}

void RegistreBorneGUI::affichageBorne(Borne* borne)
{
	int row = ui.borneTable->rowCount();
	ui.borneTable->insertRow(row);
	ui.borneTable->setItem(row, ID,
		new QTableWidgetItem(QString::number((borne->reqId()))));
	ui.borneTable->setItem(row, NOM,
		new QTableWidgetItem(QString(borne->reqNomTopographique().c_str())));
}

void RegistreBorneGUI::afficheFontaineForm()
{
	BorneFontaineInterface form(this);
	if (form.exec() == QDialog::Accepted)
	{
		try
		{
			BorneFontaine* borne = form.creerBorne();
			registre.ajouteBorne(*borne);
			affichageBorne(borne);
		}
		catch(BorneDejaPresenteException& e)
		{
			QMessageBox::information(this, "Erreur !",
				QString(e.what()));
		}
	}
}

void RegistreBorneGUI::afficheStationnementForm()
{
	BorneStationnementInterface form(this);
	if (form.exec() == QDialog::Accepted)
	{
		try
		{
			BorneStationnement* borne = form.creerBorne();
			registre.ajouteBorne(*borne);
			affichageBorne(borne);
		}
		catch(BorneDejaPresenteException& e)
		{
			QMessageBox::information(this, "Erreur !",
				QString(e.what()));
		}
	}
}

void RegistreBorneGUI::supprimerBorne()
{
	QItemSelectionModel *select = ui.borneTable->selectionModel();
	QList<QTableWidgetItem*> items = ui.borneTable->selectedItems();
	if (items.empty())
	{
		QMessageBox::information(this, "Erreur !",
			QString("Vous devez selectionner la borne a supprimer"));
		return;
	}

	int id = items[0]->text().toInt();
	registre.supprimeBorne(id);
	ui.borneTable->removeRow(select->selectedIndexes().at(0).row());
}
