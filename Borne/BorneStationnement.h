/**
 * \file BorneStationnement.h
 * \brief Fichier header de la classe BorneStationnement
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/08
 */

#ifndef BORNE_STATIONNEMENT_H_
#define BORNE_STATIONNEMENT_H_

#include "Borne.h"

namespace tp
{
/**
 * \brief La classe BorneStationnement représente les bornes de stationnement
 * 		et de paiement (horodateurs) de la ville de Québec.
 * 		Attributs :
 * 		std::string m_type : Le type de borne de stationnement peut être
 * 			« stationnement » ou « paiement »
 * 		double m_lectureMetrique : La distance mesurée à partir du début du tronçon
 * 			dans le sens des numéros d'immeuble. Il doit être plus grand que 0.
 * 		int m_segmentRue : L’identifiant du segment de voie publique.
 * 			Il doit être plus grand que 0.
 * 		std::string m_numBorne : Le numéro de la borne. Il doit être non vide.
 * 		std::string m_coteRue : Le coté par rapportau centre de chaussée
 * 			où est la borne. Il doit correspondre à un point cardinal.
 */
class BorneStationnement : public Borne
{
public:
	BorneStationnement(int p_idBorne,
			const std::string& p_direction,
			const std::string& p_nomTopographique,
			double p_longitude,
			double p_latitude,
			const std::string& p_type,
			double p_lectureMetrique,
			int p_segmentRue,
			const std::string& p_numBorne,
			const std::string& p_coteRue
	);
	virtual Borne* clone() const;
	virtual std::string reqBorneFormate() const;
	std::string reqType() const;
	double reqLectureMetrique() const;
	int reqSegmentRue() const;
	std::string reqNumBorne() const;
	std::string reqCoteRue() const;
private:
    void verifieInvariant() const;
    std::string m_type;
    double m_lectureMetrique;
    int m_segmentRue;
    std::string m_numBorne;
    std::string m_coteRue;
};
} /* namespace tp */

#endif /* BORNE_STATIONNEMENT_H_ */

