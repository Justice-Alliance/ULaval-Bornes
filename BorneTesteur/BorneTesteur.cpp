/**
 * \file BorneTesteur.cpp
 * \brief Testeur de la classe Borne
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/19
 * A tester:
 * 		Borne(int p_idBorne,
 * 		const std::string& p_direction,
 * 		const std::string& p_nomTopographique,
 * 		double p_longitude,
 * 		double p_latitude
 * 	);
 * 	bool operator==(const Borne& p_borne) const;
 * 	int reqId() const;
 * 	std::string reqDirection() const;
 * 	std::string reqNomTopographique() const;
 * 	double reqLongitude() const;
 * 	double reqLatitude() const;
 * 	void asgNomTopographique(const std::string& p_nomTopographique);
 */
#include <gtest/gtest.h>

#include "Borne.h"
#include "validationFormat.h"

using namespace tp;
using namespace util;

class BorneTest : public Borne
{
public:
	BorneTest(int p_idBorne,
			const std::string& p_direction,
			const std::string& p_nomTopographique,
			double p_longitude,
			double p_latitude
	):Borne(p_idBorne, p_direction, p_nomTopographique, p_longitude, p_latitude) {}
	virtual Borne* clone() const
	{
		return new BorneTest(*this); // Appel du constructeur copie
	}
	virtual std::string reqBorneFormate() const
	{
		return "Borne : ";
	}
};

/**
 * \brief Test du constructeur avec parametres
 * 		Cas valide : direction est un point cardinal et nom topographique non vide
 * 		Cas invalide : Toutes les conditions ne sont pas valides.
 */
TEST(BorneTest, ConstructeurValide)
{
	BorneTest borne(1, "Nord", "Nom topographique", 1.1, 2.2);

	ASSERT_EQ("Nord", borne.reqDirection());
	ASSERT_TRUE(validerPointCardinal(borne.reqDirection()));
	ASSERT_EQ("Nom topographique", borne.reqNomTopographique());
	ASSERT_TRUE(!borne.reqNomTopographique().empty());
}
TEST(Borne, DirectionInvalide)
{
	ASSERT_THROW(BorneTest(1, "North", "Nom topographique", 1.1, 2.2), ContratException);
}
TEST(Borne, NomVide)
{
	ASSERT_THROW(BorneTest(1, "Nord", "", 1.1, 2.2), ContratException);
}

/**
 * \brief Test fixture pour les methodes de la classe Borne
 */
class BorneTestValide : public ::testing::Test
{
public:
	BorneTestValide() :
		borneTestval(10, "Nord", "Nom topographique", 10.0, 20.0) {}
	BorneTest borneTestval;
};

/**
 * \brief Test de la methode bool operator==(const Borne& p_borne) const;
 */
TEST_F(BorneTestValide, opEgalValide)
{
	BorneTest borneTest(10, "Nord", "Nom topographique", 10.0, 20.0);
	ASSERT_TRUE(borneTest == borneTestval);
}

/**
 * \brief Test de la methode bool operator==(const Borne& p_borne) const;
 */
TEST_F(BorneTestValide, opEgalInvalide)
{
	BorneTest borneTest(100, "Nord", "Nom topographique", 10.0, 20.0);
	ASSERT_FALSE(borneTest == borneTestval);
}

/**
 * \brief Test de la methode int reqId() const;
 */
TEST_F(BorneTestValide, reqId)
{
	ASSERT_EQ(10, borneTestval.reqId());
}

/**
 * \brief Test de la methode std::string reqDirection() const;
 */
TEST_F(BorneTestValide, reqDirection)
{
	ASSERT_EQ("Nord", borneTestval.reqDirection());
}

/**
 * \brief Test de la methode std::string reqNomTopographique() const;
 */
TEST_F(BorneTestValide, reqNomTopographique)
{
	ASSERT_EQ("Nom topographique", borneTestval.reqNomTopographique());
}

/**
 * \brief Test de la methode double reqLongitude() const;
 */
TEST_F(BorneTestValide, reqLongitude)
{
	ASSERT_EQ(10.0, borneTestval.reqLongitude());
}

/**
 * \brief Test de la methode double reqLatitude() const;
 */
TEST_F(BorneTestValide, reqLatitude)
{
	ASSERT_EQ(20.0, borneTestval.reqLatitude());
}

/**
 * \brief Test de la methode
 * void asgNomTopographique(const std::string& p_nomTopographique);
 */
TEST_F(BorneTestValide, asgNomTopographiqueValide)
{
	ASSERT_EQ("Nom topographique", borneTestval.reqNomTopographique());
	borneTestval.asgNomTopographique("Nom 2");
	ASSERT_EQ("Nom 2", borneTestval.reqNomTopographique());
}

/**
 * \brief Test de la methode
 * void asgNomTopographique(const std::string& p_nomTopographique);
 */
TEST_F(BorneTestValide, asgNomTopographiqueInvalide)
{
	ASSERT_THROW(borneTestval.asgNomTopographique(""), ContratException);
}
