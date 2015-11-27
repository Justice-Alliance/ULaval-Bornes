/**
 * \file BorneFontaine.h
 * \brief Fichier header de la classe RegistreBorne
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/08
 */

#ifndef REGISTRE_BORNE_H_
#define REGISTRE_BORNE_H_

#include <vector>
#include "ContratException.h"
#include "BorneDejaPresenteException.h"
#include "BorneAbsenteException.h"
#include "Borne.h"

namespace tp
{
/**
 * \class RegistreBorne
 * \brief La classe RegistreBorne permet la gestion
 * 		des bornes fontaine et de stationnement.
 * 		Attributs :
 * 		std::string m_nomRegistreBorne : La version du Registre
* 			(ne doit pas être vide).
 * 		std::vector<Borne*> m_vBornes : Contient toutes les bornes
 * 			fontaine et de stationnement de la ville de Québec
 */
class RegistreBorne
{
public:
	RegistreBorne(const std::string& p_nomRegistreBorne);
	~RegistreBorne();
	void ajouteBorne(const Borne& p_Borne);
	void supprimeBorne(int p_idBorne);
	std::string reqRegistreBorneFormate() const;
	std::string reqNomRegistreBorne() const;
private:
	/* Forme de Coplien */
	RegistreBorne(const RegistreBorne& p_registreBorne);
	RegistreBorne &operator=(const RegistreBorne& p_registreBorne);

	bool BorneEstDejaPresente(const Borne& p_borne) const;
    void verifieInvariant() const;
	std::string m_nomRegistreBorne;
	std::vector<Borne*> m_vBornes;
};
} /* namespace tp */

#endif /* REGISTRE_BORNE_H_ */

