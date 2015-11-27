/**
 * \file RegistreBorne.cpp
 * \brief Implementation de la classe RegistreBorne
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/08
 */

#include <sstream>
#include "RegistreBorne.h"

using namespace std;

namespace tp
{
/**
 * \brief Constructeur de la classe.
 *      On construit un objet RegistreBorne à partir de données passées
 *      en paramètre.
 * \param[in] p_nomRegistreBorne est un string qui represente la version
 * 		du registre
 */
RegistreBorne::RegistreBorne(const string& p_nomRegistreBorne)
	: m_nomRegistreBorne(p_nomRegistreBorne)
{
	PRECONDITION(!p_nomRegistreBorne.empty());
	POSTCONDITION(m_nomRegistreBorne == p_nomRegistreBorne);
	INVARIANTS();
}

/**
 * Desctructeur de registre borne
 * un destructeur qui est responsable de désallouer toutes les
 * Bornes de la liste dans le vecteur.
 */
RegistreBorne::~RegistreBorne()
{
	vector<Borne*>::const_iterator it;
	for (it = m_vBornes.begin(); it < m_vBornes.end(); ++it)
	{
		delete (*it);
	}

	m_vBornes.clear();
}

/**
 * \brief Cette méthode permet d’ajouter une borne au vecteur de bornes
 * 		seulement si la borne n’est pas déjà présente dans cette liste.
 * \param[in] p_borne : La borne à ajouter.
 */
void RegistreBorne::ajouteBorne(const Borne& p_Borne)
{
	if(!BorneEstDejaPresente(p_Borne))
	{
		m_vBornes.push_back(p_Borne.clone());
	}
	else
	{
		throw BorneDejaPresenteException(p_Borne.reqBorneFormate());
	}

	INVARIANTS();
}

/**
 * \brief Cette méthode supprime une borne de la liste dont
 * 		l’identifiant (idBorne) est reçu en paramètre.
 * 		S’il n’y a pas de Borne qui possède cet identifiant
 * 		dans la liste des bornes, une BorneAbsenteException est lancée
 * \param[in] p_idBorne : L'identifiant de la borne à supprimer.
 */
void RegistreBorne::supprimeBorne(int p_idBorne)
{
	vector<Borne*>::iterator it;
	for (it = m_vBornes.begin(); it < m_vBornes.end(); ++it)
	{
		if ((*it)->reqId() == p_idBorne)
		{
			delete (*it);
			m_vBornes.erase(it);
			return;
		}
	}

	throw BorneAbsenteException("Id : "+ p_idBorne);
}


/**
 * \brief Cette méthode retourne dans un objet std::string les informations
 * 		formatées concernant le registre de bornes.
 * \return Un string contenant les informations formatees
 */
string RegistreBorne::reqRegistreBorneFormate() const
{
	ostringstream oss;
	oss << "Registre : " << m_nomRegistreBorne << endl;

	vector<Borne*>::const_iterator it;
	for (it = m_vBornes.begin(); it < m_vBornes.end(); ++it)
	{
		oss << (*it)->reqBorneFormate();
	}

	return oss.str();
}

/**
 * \brief Permet de vérifier si la borne n’est pas déjà dans le vecteur
 * \param[in] p_borne : La borne a tester
 * \return Si oui, elle retourne true et false dans le cas contraire.
 */
bool RegistreBorne::BorneEstDejaPresente(const Borne& p_borne) const
{
	vector<Borne*>::const_iterator it;
	for (it = m_vBornes.begin(); it < m_vBornes.end(); ++it)
	{
		if ((**it) == p_borne)
		{
			return true;
		}
	}

	return false;
}

/**
 * \brief Verifie que le nom du registre n'est pas vide
 */
void RegistreBorne::verifieInvariant() const
{
	INVARIANT(!m_nomRegistreBorne.empty());
}

/**
 * \brief La version du registre
 * \return Un string contenant la version du registre
 */
string RegistreBorne::reqNomRegistreBorne() const
{
    return m_nomRegistreBorne;
}

} /* namespace tp */
