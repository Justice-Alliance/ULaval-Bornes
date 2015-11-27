/**
 * \file RegistreBorneTesteur.cpp
 * \brief Testeur de la classe RegistreBorne
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/16
 * A tester:
 * 		RegistreBorne(const std::string& p_nomRegistreBorne);
 * 		~RegistreBorne();
 * 		void ajouteBorne(const Borne& p_Borne);
 * 		std::string reqRegistreBorneFormate() const;
 * 		std::string reqNomRegistreBorne() const;
 */
#include <gtest/gtest.h>

#include "RegistreBorne.h"
#include "BorneFontaine.h"
#include "validationFormat.h"

using namespace tp;
using namespace util;

/**
 * \brief Test du constructeur avec parametres
 * 		Cas valide : nomRegistreBorne non vide
 * 		Cas invalide : nomRegistreBorne vide
 */
TEST(RegistreBorne, ConstructeurValide)
{
	RegistreBorne registreBorne("Registre");

	ASSERT_EQ("Registre", registreBorne.reqNomRegistreBorne());
	ASSERT_TRUE(!registreBorne.reqNomRegistreBorne().empty());
}
TEST(RegistreBorne, NomVide)
{
	ASSERT_THROW(RegistreBorne(""), ContratException);
}

/**
 * \brief Test fixture pour les methodes de la classe RegistreBorne
 */
class RegistreBorneValide : public ::testing::Test
{
public:
	RegistreBorneValide() :
		registreBorneVal("Registre") {}
	RegistreBorne registreBorneVal;
};

/**
 * \brief Test de la methode void ajouteBorne(const Borne& p_Borne);
 */
TEST_F(RegistreBorneValide, ajouteBorne)
{
	std::ostringstream oss;
	oss << "Registre : " << registreBorneVal.reqNomRegistreBorne() << std::endl;

	ASSERT_EQ(oss.str(), registreBorneVal.reqRegistreBorneFormate());
	registreBorneVal.ajouteBorne(BorneFontaine(10, "Nord", "Nom", 11.1, 22.2,
		"Québec", "Arrondissement"));
	ASSERT_NE(oss.str(), registreBorneVal.reqRegistreBorneFormate());
}
/**
 * \brief Test de la methode void ajouteBorne(const Borne& p_Borne);
 */
TEST_F(RegistreBorneValide, ajouteBorneInvalide)
{
	std::ostringstream oss;
	oss << "Registre : " << registreBorneVal.reqNomRegistreBorne() << std::endl;
	BorneFontaine borne(10, "Nord", "Nom", 11.1, 22.2,
			"Québec", "Arrondissement");


	ASSERT_EQ(oss.str(), registreBorneVal.reqRegistreBorneFormate());
	registreBorneVal.ajouteBorne(borne);
	ASSERT_NE(oss.str(), registreBorneVal.reqRegistreBorneFormate());
	ASSERT_THROW(registreBorneVal.ajouteBorne(borne),
		BorneDejaPresenteException);
}

/**
 * \brief Test de la methode void supprimeBorne(int p_idBorne);
 */
TEST_F(RegistreBorneValide, supprimeBorneValide)
{
	std::ostringstream oss;
	oss << "Registre : " << registreBorneVal.reqNomRegistreBorne() << std::endl;
	BorneFontaine borne(10, "Nord", "Nom", 11.1, 22.2,
			"Québec", "Arrondissement");

	ASSERT_EQ(oss.str(), registreBorneVal.reqRegistreBorneFormate());
	registreBorneVal.ajouteBorne(borne);
	ASSERT_NE(oss.str(), registreBorneVal.reqRegistreBorneFormate());

	registreBorneVal.supprimeBorne(10);
	ASSERT_EQ(oss.str(), registreBorneVal.reqRegistreBorneFormate());
}
/**
 * \brief Test de la methode void supprimeBorne(int p_idBorne);
 */
TEST_F(RegistreBorneValide, supprimeBorneInvalide)
{
	ASSERT_THROW(registreBorneVal.supprimeBorne(10), BorneAbsenteException);
}

/**
 * \brief Test de la methode std::string reqRegistreBorneFormate() const;
 */
TEST_F(RegistreBorneValide, reqBorneFormate)
{
	std::ostringstream oss;
		oss << "Registre : " << registreBorneVal.reqNomRegistreBorne() << std::endl;

		ASSERT_EQ(oss.str(), registreBorneVal.reqRegistreBorneFormate());

		BorneFontaine borneFontaine(10, "Nord", "Nom", 11.1, 22.2,
				"Québec", "Arrondissement");
		registreBorneVal.ajouteBorne(borneFontaine);
		ASSERT_EQ(oss.str()+borneFontaine.reqBorneFormate(),
			registreBorneVal.reqRegistreBorneFormate());
}

/**
 * \brief Test de la methode std::string reqNomRegistreBorne() const;
 */
TEST_F(RegistreBorneValide, reqNomRegistreBorne)
{
	ASSERT_EQ("Registre", registreBorneVal.reqNomRegistreBorne());
}

