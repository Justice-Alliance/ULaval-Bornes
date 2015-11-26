/**
 * \file Borne.h
 * \brief Fichier header de la classe Borne
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/08
 */

#ifndef BORNE_H_
#define BORNE_H_

#include <string>
#include "ContratException.h"

namespace tp
{
/**
 * \class Borne
 * \brief Cette classe permet de modéliser tous les types de bornes présents
 *      dans la ville de Quebec.
 *      Attributs:
 *          int m_idBorne : L’identifiant de la borne.
 *          std::string m_direction : Le coté du centre de chaussée où
 *          	l’intersection dans le cas d’un terre-plein. Il doit correspondre
 *          	à un point cardinal.
 *          std::string m_nomTopographique : Le nom topographique
 *          	(générique, liaison, spécifique, direction) du centre de chaussée.
 *          	Il doit être non vide.
*          	double m_longitude : La longitude
*          	double m_latitude : La latitude
 */
class Borne
{
public:
    Borne(int p_idBorne,
		const std::string& p_direction,
		const std::string& p_nomTopographique,
		double p_longitude,
		double p_latitude
	);
    virtual ~Borne();
    virtual Borne* clone() const = 0;
    bool operator==(const Borne& p_borne) const;
    virtual std::string reqBorneFormate() const = 0;
    int reqId() const;
    std::string reqDirection() const;
    std::string reqNomTopographique() const;
    double reqLongitude() const;
    double reqLatitude() const;
    void asgNomTopographique(const std::string& p_nomTopographique);

private:
    void verifieInvariant() const;
    int m_idBorne;
    std::string m_direction;
    std::string m_nomTopographique;
    double m_longitude;
    double m_latitude;
};

} /* namespace tp */

#endif /* BORNE_H_ */

