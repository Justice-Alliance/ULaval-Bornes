/**
 * \file BorneFontaine.h
 * \brief Fichier header de la classe BorneFontaine
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/08
 */

#ifndef BORNE_FONTAINE_H_
#define BORNE_FONTAINE_H_

#include "Borne.h"

namespace tp
{
/**
 * \class BorneFontaine
 * \brief La classe BorneFontaine représente les bornes fontaine
 * 		de la ville de Québec.
 * 		Attributs :
 * 		std::string m_ville : La ville
 * 		std::string m_arrondissement : L'arrondissement
 * 			L’arrondissement ne doit pas être vide si la ville est « Quebec »
 */
class BorneFontaine : public Borne
{
public:
	BorneFontaine(int p_idBorne,
			const std::string& p_direction,
			const std::string& p_nomTopographique,
			double p_longitude,
			double p_latitude,
			const std::string& p_ville,
			const std::string& p_arrondissement
	);
	virtual Borne* clone() const;
	virtual std::string reqBorneFormate() const;
	std::string reqVille() const;
	std::string reqArrondissement() const;
private:
    void verifieInvariant() const;
	std::string m_ville;
	std::string m_arrondissement;
};
} /* namespace tp */

#endif /* BORNE_FONTAINE_H_ */

