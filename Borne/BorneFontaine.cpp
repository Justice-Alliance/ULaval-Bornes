/**
 * \file BorneFontaine.cpp
 * \brief Implementation de la classe BorneFontaine
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/08
 */

#include <sstream>

#include "BorneFontaine.h"

using namespace std;

namespace tp
{
/**
 * \brief Constructeur de la classe.
 *      On construit un objet BorneFontaine à partir de données passées
*      	en paramètre.
 * \param[in] p_idBorne est un int qui represente le numéro de la borne
 * \param[in] p_direction est un string qui represente le cote
 * 		du centre de la chaussee
 * \param[in] p_nomTopographique est un string qui represente
 * 		le nom du centre de la chaussee
 * \param[in] p_longitude est un double qui represente la longitude
 * \param[in] p_latitude est un double qui represente la latitude
 * \param[in] p_ville est un string qui represente la ville
 * \param[in] p_arrondissement est un string qui represente l'arrondissement
 */
BorneFontaine::BorneFontaine(int p_idBorne,
		const string& p_direction,
		const string& p_nomTopographique,
		double p_longitude,
		double p_latitude,
		const string& p_ville,
		const string& p_arrondissement)
	: Borne(p_idBorne, p_direction, p_nomTopographique, p_longitude, p_latitude),
	  m_ville(p_ville), m_arrondissement(p_arrondissement)
{
	PRECONDITION(!p_ville.empty());
	if (m_ville == "Québec")
	{
		PRECONDITION(!p_arrondissement.empty());
	}
	else
	{
		PRECONDITION(p_arrondissement.empty());
	}

	POSTCONDITION(m_ville == p_ville);
	POSTCONDITION(m_arrondissement == p_arrondissement);

	INVARIANTS();
}

/**
 * \brief Cette méthode permet de faire une copie allouée
 * 		sur le monceau de l'objet courant.
 * \return Une copie allouée de l'objet courant
 */
Borne* BorneFontaine::clone() const
{
	return new BorneFontaine(*this); // Appel du constructeur copie
}

/**
 * \brief Formate les informations d'une borne fontaine
 * \return Un string contenant les informations formatees
 */
std::string BorneFontaine::reqBorneFormate() const
{
	ostringstream oss;
	oss << "Borne fontaine :" << endl;
	oss << "----------------------------------------------" << endl;
	oss << "Identifiant de la borne : " << reqId() << endl;
	oss << "Direction : " << reqDirection() << endl;
	oss << "Nom topographique : " << reqNomTopographique() << endl;
	oss << "Longitude : " << reqLongitude() << endl;
	oss << "Latitude : " << reqLatitude() << endl;
	oss << "Ville : " << m_ville << endl;
	oss << "Arrondissement : " << m_arrondissement << endl;

	return oss.str();
}

/**
 * \brief Verifie que le nom topographique n'est pas vide et
 * 		que l'arrondissement n'est pas vide si la ville est « Quebec »
 */
void BorneFontaine::verifieInvariant() const
{
	if (m_ville == "Québec")
	{
		INVARIANT(!m_arrondissement.empty());
	}
}

/**
 * \brief La ville
 * \return Un string contenant la ville
 */
string BorneFontaine::reqVille() const
{
    return m_ville;
}

/**
 * \brief L'arrondissement
 * \return Un string contenant l'arrondissement
 */
string BorneFontaine::reqArrondissement() const
{
    return m_arrondissement;
}

} /* namespace tp */

