#include <iostream>

#include "RegistreBorne.h"
#include "BorneFontaine.h"
#include "BorneStationnement.h"
#include "validationFormat.h"

using namespace std;
using namespace tp;
using namespace util;

int main(int argc, char** argv)
{
	/*
	 * 1. Le programme commence par construire un registre
	 * (dont le nom est fixé à priori; il n’est donc pas saisi).
	 */
	RegistreBorne registre("Registre v1");

	/*
	 * 2. Il est ensuite demandé à l’usager de saisir des informations pour créer
	 * puis ajouter successivement deux nouvelles bornes
	 * (une borne fontaine et une borne de stationnement).
	 */
	int idBorne = 0;
	string direction;
	string nomTopographique;
	double longitude = 0.0;
	double latitude = 0.0;
	string ville;
	string arrondissement;

	/* 2.1 Borne fontaine */
	cout << "Borne fontaine" << endl;
	cout << "Id de la borne :" << endl;
	cin >> idBorne;
	do
	{
		cout << "Direction (Point cardinal) :" << endl;
		cin >> direction;
	} while (!validerPointCardinal(direction));
	while (nomTopographique.empty())
	{
		cout << "Nom topographique (Non vide) :" << endl;
		cin >> nomTopographique;
	}
	cout << "Longitude :" << endl;
	cin >> longitude;
	cout << "Latitude :" << endl;
	cin >> latitude;
	cout << "Ville :" << endl;
	cin >> ville;
	if ("Quebec" == ville)
	{
		while (arrondissement.empty())
		{
			cout << "Arrondissement (non vide) :" << endl;
			cin >> arrondissement;
		}
	}
	else
	{
		cout << "Arrondissement :" << endl;
		cin >> arrondissement;
	}
	registre.ajouteBorne(BorneFontaine(idBorne, direction, nomTopographique,
		longitude, latitude, ville, arrondissement));

	/* 2.2 Borne de stationnement */
	string type;
	double lectureMetrique = 0.0;
	int segmentRue = 0;
	string numBorne;
	string coteRue;

	cout << endl << "Borne de stationnement" << endl;
	cout << "Id de la borne :" << endl;
	cin >> idBorne;
	do
	{
		cout << "Direction (Point cardinal) :" << endl;
		cin >> direction;
	} while (!validerPointCardinal(direction));
	while (nomTopographique.empty())
	{
		cout << "Nom topographique (Non vide) :" << endl;
		cin >> nomTopographique;
	}
	cout << "Longitude :" << endl;
	cin >> longitude;
	cout << "Latitude :" << endl;
	cin >> latitude;
	while ("stationnement" != type && type != "paiement")
	{
		cout << "Type (stationnement ou paiement):" << endl;
		cin >> type;
	}
	while (lectureMetrique <= 0.0)
	{
		cout << "Lecture metrique (>0.0):" << endl;
		cin >> lectureMetrique;
	}
	while (segmentRue <= 0)
	{
		cout << "Segment rue (>0):" << endl;
		cin >> segmentRue;
	}
	while (numBorne.empty())
	{
		cout << "Num borne (non vide):" << endl;
		cin >> numBorne;
	}
	do
	{
		cout << "Cote rue (Point cardinal):" << endl;
		cin >> coteRue;
	} while (!validerPointCardinal(coteRue));

	registre.ajouteBorne(BorneStationnement(idBorne, direction, nomTopographique,
		longitude, latitude, type, lectureMetrique, segmentRue, numBorne, coteRue));

	/* 3 Le contenu du registre est alors affiché au complet. */
	cout << registre.reqRegistreBorneFormate() << endl;

	return 0;
}

