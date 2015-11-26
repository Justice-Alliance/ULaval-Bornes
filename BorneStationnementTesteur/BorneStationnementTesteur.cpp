/**
 * \file BorneStationnementTesteur.cpp
 * \brief Testeur de la classe BorneStationnement
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/16
 * A tester:
 *		BorneStationnement(int p_idBorne,
 *			const std::string& p_direction,
 *			const std::string& p_nomTopographique,
 *			double p_longitude,
 *			double p_latitude,
 *			const std::string& p_type,
 *			double p_lectureMetrique,
 *			int p_segmentRue,
 *			const std::string& p_numBorne,
 *			const std::string& p_coteRue
 *	);
 *	virtual Borne* clone() const;
 *	virtual std::string reqBorneFormate() const;
 *	std::string reqType() const;
 *	double reqLectureMetrique() const;
 *	int reqSegmentRue() const;
 *	std::string reqNumBorne() const;
 *	std::string reqCoteRue() const;
 */
#include <gtest/gtest.h>

#include "BorneStationnement.h"
#include "validationFormat.h"

using namespace tp;
using namespace util;

/**
 * \brief Test du constructeur avec parametres
 * 		Cas valide : type = stationnement ou paiement, lectureMetrique > 0.0,
 * 			segmentRue > 0, numBorne non vide, coteRue est un point cardinal
 * 		Cas invalide : Toutes les contraintes du cas valide ne sont pas respectées
 */
TEST(borneStationnement, ConstructeurValide)
{
	BorneStationnement borneStationnement(10, "Nord", "Nom topographique", 10.0, 20.0,
		"stationnement", 1.0, 1, "Numero", "Sud");

	ASSERT_EQ("stationnement", borneStationnement.reqType());
	ASSERT_EQ(1.0, borneStationnement.reqLectureMetrique());
	ASSERT_EQ(1, borneStationnement.reqSegmentRue());
	ASSERT_EQ("Numero", borneStationnement.reqNumBorne());
	ASSERT_TRUE(!borneStationnement.reqNumBorne().empty());
	ASSERT_EQ("Sud", borneStationnement.reqCoteRue());
	ASSERT_TRUE(validerPointCardinal(borneStationnement.reqCoteRue()));
}
TEST(BorneStationnement, ConstructeurInvalide)
{
	ASSERT_THROW(BorneStationnement(10, "Nord", "Nom topographique", 10.0, 20.0,
		"stationement", 0, 0, "", "South"), ContratException);
}

/**
 * \brief Test fixture pour les methodes de la classe BorneStationnement
 */
class BorneStationnementValide : public ::testing::Test
{
public:
	BorneStationnementValide() :
		borneStationnementVal(10, "Nord", "Nom topographique", 10.0, 20.0,
				"stationnement", 1.0, 1, "Numero", "Sud") {}
	BorneStationnement borneStationnementVal;
};

/**
 * \brief Test de la methode virtual Borne* clone() const;
 */
TEST_F(BorneStationnementValide, clone)
{
	ASSERT_EQ(borneStationnementVal, *(borneStationnementVal.clone()));
}

/**
 * \brief Test de la methode std::string reqBorneFormate() const;
 */
TEST_F(BorneStationnementValide, reqBorneFormate)
{
	std::ostringstream oss;
	oss << "Borne de " << borneStationnementVal.reqType() << " : " << std::endl;
	oss << "----------------------------------------------" << std::endl;
	oss << "Identifiant de la borne : " << borneStationnementVal.reqId() << std::endl;
	oss << "Direction : " << borneStationnementVal.reqDirection() << std::endl;
	oss << "Nom topographique : " << borneStationnementVal.reqNomTopographique() << std::endl;
	oss << "Longitude : " << borneStationnementVal.reqLongitude() << std::endl;
	oss << "Latitude : " << borneStationnementVal.reqLatitude() << std::endl;
	oss << "Distance mesuree : " << borneStationnementVal.reqLectureMetrique() << std::endl;
	oss << "Segment de rue : " << borneStationnementVal.reqSegmentRue() << std::endl;
	oss << "Numero de borne : " << borneStationnementVal.reqNumBorne() << std::endl;
	oss << "Cote de la rue : " << borneStationnementVal.reqCoteRue() << std::endl;

	ASSERT_EQ(oss.str(), borneStationnementVal.reqBorneFormate());
}

/**
 * \brief Test de la methode std::string reqType() const;
 */
TEST_F(BorneStationnementValide, reqVille)
{
	ASSERT_EQ("stationnement", borneStationnementVal.reqType());
}

/**
 * \brief Test de la methode double reqLectureMetrique() const;
 */
TEST_F(BorneStationnementValide, reqLectureMetrique)
{
	ASSERT_EQ(1.0, borneStationnementVal.reqLectureMetrique());
}

/**
 * \brief Test de la methode int reqSegmentRue() const;
 */
TEST_F(BorneStationnementValide, reqSegmentRue)
{
	ASSERT_EQ(1.0, borneStationnementVal.reqSegmentRue());
}

/**
 * \brief Test de la methode std::string reqNumBorne() const;
 */
TEST_F(BorneStationnementValide, reqNumBorne)
{
	ASSERT_EQ("Numero", borneStationnementVal.reqNumBorne());
}

/**
 * \brief Test de la methode std::string reqCoteRue() const;
 */
TEST_F(BorneStationnementValide, reqCoteRue)
{
	ASSERT_EQ("Sud", borneStationnementVal.reqCoteRue());
}

