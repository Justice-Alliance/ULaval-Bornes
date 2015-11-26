/**
 * \file Borne.cpp
 * \brief Implementation de la classe Borne
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/08
 */

#include "Borne.h"
#include "validationFormat.h"

using namespace std;
using namespace util;

namespace tp
{
/**
 * \brief Constructeur de la classe.
 *      On construit un objet Borne à partir de données passées en paramètre.
 * \param[in] p_idBorne est un int qui represente le numéro de la borne
 * \param[in] p_direction est un string qui represente le cote
 * 		du centre de la chaussee
 * \param[in] p_nomTopographique est un string qui represente
 * 		le nom du centre de la chaussee
 * \param[in] p_longitude est un double qui represente la longitude
 * \param[in] p_latitude est un double qui represente la latitude
 */
Borne::Borne(int p_idBorne,
		const string& p_direction,
		const string& p_nomTopographique,
		double p_longitude,
		double p_latitude)
	: m_idBorne(p_idBorne), m_direction(p_direction),
	  m_nomTopographique(p_nomTopographique), m_longitude(p_longitude),
	  m_latitude(p_latitude)
{
	PRECONDITION(validerPointCardinal(p_direction));
	PRECONDITION(!p_nomTopographique.empty());

	POSTCONDITION(m_idBorne == p_idBorne);
	POSTCONDITION(m_direction == p_direction);
	POSTCONDITION(m_nomTopographique == p_nomTopographique);
	POSTCONDITION(m_longitude == p_longitude);
	POSTCONDITION(m_latitude == p_latitude);

	INVARIANTS();
}

/**
 * \brief Destructeur virtuel de la classe Borne
 */
Borne::~Borne()
{
}

/**
 * \brief Opérateur de comparaison d’égalité.
 *      La comparaison se fait sur la base de tous les attributs.
 * \param[in] p_borne est l'objet Borne a comparer
 * \return Un booleen qui indique l'egalite
 */
bool Borne::operator==(const Borne& p_borne) const
{
    return m_idBorne == p_borne.m_idBorne &&
            m_direction == p_borne.m_direction &&
            m_nomTopographique == p_borne.m_nomTopographique &&
            m_longitude == p_borne.m_longitude &&
            m_latitude == p_borne.m_latitude;
}

/**
 * \brief Verifie que le nom topographique n'est pas vide
 */
void Borne::verifieInvariant() const
{
	INVARIANT(validerPointCardinal(m_direction));
	INVARIANT(!m_nomTopographique.empty());
}

/**
 * \brief Le numéro de la borne.
 * \return Un int contenant le numero de la borne
 */
int Borne::reqId() const
{
    return m_idBorne;
}

/**
 * \brief Le coté du centre de chaussée ou l’intersection dans le cas
 * 		d’un terre-plein.
 * \return Un string contenant le cote du centre de la chaussee
 */
string Borne::reqDirection() const
{
    return m_direction;
}

/**
 * \brief Le nom topographique (générique, liaison, spécifique, direction)
 * 		du centre de chaussée.
 * \return Un string contenant le nom topographique
 */
string Borne::reqNomTopographique() const
{
    return m_nomTopographique;
}

/**
 * \brief La longitude
 * \return Un double contenant la longitude
 */
double Borne::reqLongitude() const
{
	return m_longitude;
}

/**
 * \brief La latitude
 * \return Un double contenant la latitude
 */
double Borne::reqLatitude() const
{
	return m_latitude;
}

/**
 * \brief Methode permettant de changer le nom topographique de la borne.
 * \param[in] Le nouveau nom topographique
 */
void Borne::asgNomTopographique(const string& p_nomTopographique)
{
	PRECONDITION(!p_nomTopographique.empty());
    m_nomTopographique = p_nomTopographique;
    POSTCONDITION(m_nomTopographique == p_nomTopographique);
    INVARIANTS();
}

} /* namespace tp */

