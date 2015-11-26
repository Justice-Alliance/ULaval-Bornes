/*
 * validationFormat.cpp
 *
 *  Created on: 2015-09-19
 *      Author: etudiant
 */

#include "validationFormat.h"

#include <iostream>
#include <sstream>

using namespace std;

/**
 * \brief Methode qui permet de convertir une chaine de caracteres
 * de la forme 123,456 en double.
 * \param[in] p_chaine la chaine de caracteres a convertir.
 * \return un double resultat de la conversion.
 */
double convertirChaineEnDouble(std::string& p_chaine)
{
	//on remplace la , en .
	for (unsigned int i = 0; i < p_chaine.length(); i++)
	{
		if (p_chaine[i] == ',')
		{
			p_chaine[i] = '.';
		}
	}
	istringstream is(p_chaine);
	double chaineConvertiEnDouble;
	is >> chaineConvertiEnDouble;

	return chaineConvertiEnDouble;
}

string removeQuotes(string str)
{
	return (str != "null") ? str.substr(1, str.length()-2) : "null";
}

namespace util
{
	/**
	 * Pour la validation du format GeoJson, on limitera à reconnaitre les noms des propriétés :
	 * attention les noms des propriétés vont inclure les " pour la validation.
	 */
	bool valideLigneGEOJSON (string& p_ligne, ostringstream& p_parametres)
	{
		string ELEM[8] = {"ID", "COTE_RUE", "LECT_MET", "SEGMENT_RU",
			"DIRECTION", "NOM_TOPOG", "NO_BORNE", "GEOM"};
		p_parametres.flush();
		ostringstream parameters;
		unsigned cpt = 0;
		string line(p_ligne);
		char buffer[256];

		size_t pos1 = line.find("\"properties\":{");
		if (pos1 != string::npos)
		{
			line = line.substr(pos1+14);
			line = line.substr(0, line.length()-3);
			istringstream isLine(line);
			while (isLine.getline(buffer, 255, ','))
			{
				istringstream isLine2(buffer);
				isLine2.getline(buffer, 255, ':');

				string strBuffer = removeQuotes(string(buffer));
				for (unsigned i = 0; i < 8; ++i)
				{
					if (strBuffer == ELEM[i])
					{
						isLine2.getline(buffer, 255, ':');
						parameters << removeQuotes(buffer) << ',';
						++cpt;
					}
				}
			}

			if (8 == cpt)
			{
				p_parametres.str(parameters.str());
				return true;
			}
		}

		return false;
	}

	/**
	 * Pour le format CVS, on se limitera à vérifier que l'on a le bon nombre de propriétés
	 * séparées par des |
	 */
	bool valideLigneCVS (string& p_ligne, ostringstream& p_parametres)
	{
		p_parametres.flush();
		ostringstream parameters;
		istringstream isLine(p_ligne);
		char buffer[256];
		int cpt = 0;

		while (isLine.getline(buffer, 255, '|'))
		{
			cpt++;
			if (3 == cpt || 4 == cpt || cpt > 7)
			{
				string str(buffer);
				parameters << convertirChaineEnDouble(str);
			}
			else
			{
				parameters << buffer;
			}
			parameters << ',';
		}

		if (cpt != 9)
		{
			return false;
		}

		p_parametres.str(parameters.str());
		return true;
	}

	/**
	 * Cette fonction valide la longitude et la latitude de la borne de stationnement
	 * selon le standard WKT (Well-Known Text).
	 * Le format à valider doit être le suivant :
	 * POINT (longitude latitude) où longitude et latitude sont des éléments de type double.
	 */
	bool validerGeom(const string& p_geom)
	{
		string geom = p_geom;
		size_t pos1 = geom.find("POINT (");
		if (pos1 != string::npos)
		{
			geom = geom.substr(pos1+7);
			size_t pos2 = geom.find(" ");
			if (pos2 != string::npos)
			{
				string strLongitude = geom.substr(0, pos2);
				size_t pos3 = geom.find(")");
				if (pos3 != string::npos && (pos3+1) == geom.length())
				{
					string strLatitude = geom.substr(pos2+1, pos3);
					if (0 == strLongitude.length() || strLatitude.length() == 0)
					{
						return false;
					}

					return true;
				}
			}
		}

		return false;
	}

	/**
		 * Cette fonction valide le format d’un point cardinal.
		 * Les valeurs possibles d’un point cardinal sont : Nord, Sud, Est, Ouest, null,
		 * 		« chaine vide ».
		 */
		bool validerPointCardinal(const string& p_cardinalite)
		{
			return "Nord" == p_cardinalite ||
				"Sud" == p_cardinalite ||
				"Est" == p_cardinalite ||
				"Ouest" == p_cardinalite ||
				"null" == p_cardinalite ||
				p_cardinalite.empty();
		}
} /* namespace util */
