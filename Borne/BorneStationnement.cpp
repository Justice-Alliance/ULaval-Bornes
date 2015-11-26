/**
 * \file BorneStationnement.cpp
 * \brief Implementation de la classe BorneStationnement
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/08
 */

#include <sstream>

#include "BorneStationnement.h"
#include "validationFormat.h"

using namespace std;
using namespace util;

namespace tp
{
/**
 * \brief Constructeur de la classe.
 *      On construit un objet BorneStationnement à partir de données passées
 *      en paramètre.
 * \param[in] p_idBorne est un int qui represente le numéro de la borne
 * \param[in] p_direction est un string qui represente le cote du centre
 * 		de la chaussee
 * \param[in] p_nomTopographique est un string qui represente le nom du
 * 		centre de la chaussee
 * \param[in] p_longitude est un double qui represente la longitude
 * \param[in] p_latitude est un double qui represente la latitude
 * \param[in] p_type est un string qui represente le type de borne
 * \param[in] p_lectureMetrique est un double qui reprensente la distance
 * 		entre le début du tronçon dans le sens des numéros d'immeuble
 * \param[in] p_segmentRue est un int qui represente l'identifiant
 * 		du segment de voie publique
 * \param[in] p_numBorne est un string qui represente le numero de la borne
 * \param[in] p_coteRue est un string qui represente Le coté
 * 		par rapport au centre de chaussée où est la borne.
 */
BorneStationnement::BorneStationnement(int p_idBorne,
		const string& p_direction,
		const string& p_nomTopographique,
		double p_longitude,
		double p_latitude,
		const string& p_type,
		double p_lectureMetrique,
		int p_segmentRue,
		const string& p_numBorne,
		const string& p_coteRue)
	: Borne(p_idBorne, p_direction, p_nomTopographique, p_longitude, p_latitude),
	  m_type(p_type), m_lectureMetrique(p_lectureMetrique),
	  m_segmentRue(p_segmentRue), m_numBorne(p_numBorne), m_coteRue(p_coteRue)
{
	PRECONDITION("stationnement" == p_type || p_type == "paiement");
	PRECONDITION(p_lectureMetrique > 0.0);
	PRECONDITION(p_segmentRue > 0);
	PRECONDITION(!p_numBorne.empty());
	PRECONDITION(validerPointCardinal(p_coteRue));

	POSTCONDITION(m_type == p_type);
	POSTCONDITION(m_lectureMetrique == p_lectureMetrique);
	POSTCONDITION(m_segmentRue == p_segmentRue);
	POSTCONDITION(m_numBorne == p_numBorne);
	POSTCONDITION(m_coteRue == p_coteRue)

	INVARIANTS();
}

/**
 * \brief Cette méthode permet de faire une copie allouée
 * 		sur le monceau de l'objet courant.
 * \return Une copie allouée de l'objet courant
 */
Borne* BorneStationnement::clone() const
{
	return new BorneStationnement(*this); // Appel du constructeur copie
}

/**
 * \brief Formate les informations d'une borne stationnement
 * \return Un string contenant les informations formatees
 */
std::string BorneStationnement::reqBorneFormate() const
{
	ostringstream oss;
	oss << "Borne de " << m_type << " : " << endl;
	oss << "----------------------------------------------"<< endl;
	oss << "Identifiant de la borne : " << reqId() << endl;
	oss << "Direction : " << reqDirection() << endl;
	oss << "Nom topographique : " << reqNomTopographique() << endl;
	oss << "Longitude : " << reqLongitude() << endl;
	oss << "Latitude : " << reqLatitude() << endl;
	oss << "Distance mesuree : " << m_lectureMetrique << endl;
	oss << "Segment de rue : " << m_segmentRue << endl;
	oss << "Numero de borne : " << m_numBorne << endl;
	oss << "Cote de la rue : " << m_coteRue << endl;

	return oss.str();
}

/**
 * \brief Verifie que le nom topographique n'est pas vide,
 * 		le type est soit "stationnement" soit "paiement",
 * 		la lecture metrique est > 0,
 * 		le segement rue est > 0,
 * 		le numero de borne n'est pas vide
 */
void BorneStationnement::verifieInvariant() const
{
	INVARIANT("stationnement" == m_type || m_type == "paiement");
	INVARIANT(m_lectureMetrique > 0.0);
	INVARIANT(m_segmentRue > 0);
	INVARIANT(!m_numBorne.empty());
	INVARIANT(validerPointCardinal(m_coteRue));
}

/**
 * \brief Le type
 * \return Un string contenant le type de borne
 */
string BorneStationnement::reqType() const
{
    return m_type;
}

/**
 * \brief La lecture metrique
 * \return Un double contenant la lecture metrique
 */
double BorneStationnement::reqLectureMetrique() const
{
    return m_lectureMetrique;
}

/**
 * \brief Le segment de rue
 * \return Un string contenant le segment de rue
 */
int BorneStationnement::reqSegmentRue() const
{
    return m_segmentRue;
}

/**
 * \brief Le numero de borne
 * \return Un string contenant le numero de borne
 */
string BorneStationnement::reqNumBorne() const
{
    return m_numBorne;
}

/**
 * \brief Le cote rue
 * \return Un string contenant le cote rue
 */
string BorneStationnement::reqCoteRue() const
{
    return m_coteRue;
}
} /* namespace tp */

