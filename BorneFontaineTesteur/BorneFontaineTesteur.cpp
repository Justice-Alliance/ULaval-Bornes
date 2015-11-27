/**
 * \file BorneFontaineTesteur.cpp
 * \brief Testeur de la classe BorneFontaine
 * \aauthor Pascal Tung
 * \version 1.0
 * \date 15/11/11
 * A tester:
 *		BorneFontaine(int p_idBorne,
 *			const std::string& p_direction,
 *			const std::string& p_nomTopographique,
 *			double p_longitude,
 *			double p_latitude,
 *			const std::string& p_ville,
 *			const std::string& p_arrondissement
 *		);
 *	virtual Borne* clone() const;
 *	virtual std::string reqBorneFormate() const;
 *	std::string reqVille() const;
 *	std::string reqArrondissement() const;
 */
#include <gtest/gtest.h>

#include "BorneFontaine.h"
#include "validationFormat.h"

using namespace tp;
using namespace util;

/**
 * \brief Test du constructeur avec parametres
 * 		Cas valide : ville et arrondissement initialises
 * 		Cas invalide : arrondissement vide si ville = "Quebec"
 */
TEST(BorneFontaine, ConstructeurValideNonQuebec)
{
	BorneFontaine borneFontaine(10, "Nord", "Nom topographique", 10.0, 20.0,
		"Ville", "");

	ASSERT_EQ("Ville", borneFontaine.reqVille());
	ASSERT_EQ("", borneFontaine.reqArrondissement());
}
TEST(BorneFontaine, ConstructeurValideQuebec)
{
	BorneFontaine borneFontaine(10, "Nord", "Nom topographique", 10.0, 20.0,
		"Québec", "Arrondissement");

	ASSERT_EQ("Québec", borneFontaine.reqVille());
	ASSERT_EQ("Arrondissement", borneFontaine.reqArrondissement());
}
TEST(BorneFontaine, ArrondissementNonVide)
{
	ASSERT_THROW(BorneFontaine(10, "Nord", "Nom topographique", 10.0, 20.0,
		"Ville", "Arrondissement"), ContratException);
}
TEST(BorneFontaine, ArrondissementVide)
{
	ASSERT_THROW(BorneFontaine(10, "Nord", "Nom topographique", 10.0, 20.0,
		"Québec", ""), ContratException);
}

/**
 * \brief Test fixture pour les methodes de la classe BorneFontaine
 */
class BorneFontaineValide : public ::testing::Test
{
public:
	BorneFontaineValide() :
		borneFontaineVal(10, "Nord", "Nom topographique", 10.0, 20.0,
			"Québec", "Arrondissement") {}
	BorneFontaine borneFontaineVal;
};

/**
 * \brief Test de la methode virtual Borne* clone() const;
 */
TEST_F(BorneFontaineValide, clone)
{
	ASSERT_EQ(borneFontaineVal, *(borneFontaineVal.clone()));
}

/**
 * \brief Test de la methode std::string reqBorneFormate() const;
 */
TEST_F(BorneFontaineValide, reqBorneFormate)
{
	std::ostringstream oss;
	oss << "Borne fontaine :" << std::endl;
	oss << "----------------------------------------------" << std::endl;
	oss << "Identifiant de la borne : " << borneFontaineVal.reqId() << std::endl;
	oss << "Direction : " << borneFontaineVal.reqDirection() << std::endl;
	oss << "Nom topographique : " << borneFontaineVal.reqNomTopographique() << std::endl;
	oss << "Longitude : " << borneFontaineVal.reqLongitude() << std::endl;
	oss << "Latitude : " << borneFontaineVal.reqLatitude() << std::endl;
	oss << "Ville : " << borneFontaineVal.reqVille() << std::endl;
	oss << "Arrondissement : " << borneFontaineVal.reqArrondissement() << std::endl;

	ASSERT_EQ(oss.str(), borneFontaineVal.reqBorneFormate());
}

/**
 * \brief Test de la methode std::string reqVille() const;
 */
TEST_F(BorneFontaineValide, reqVille)
{
	ASSERT_EQ("Québec", borneFontaineVal.reqVille());
}

/**
 * \brief Test de la methode std::string reqArrondissement() const;
 */
TEST_F(BorneFontaineValide, reqArrondissement)
{
	ASSERT_EQ("Arrondissement", borneFontaineVal.reqArrondissement());
}

