/**
 * \file BorneDejaPresenteException.h
 * \brief Fichier header de la classe BorneDejaPresenteException
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/27
 */

#ifndef BORNE_DEJA_PRESENTE_EXCEPTION_H_
#define BORNE_DEJA_PRESENTE_EXCEPTION_H_

#include "BorneException.h"

namespace tp {

/**
 * \class BorneDejaPresenteException
 * \brief Cette classe permet de gérer l’exception de l’ajout
 * 		d’un doublon de Borne dans la liste des bornes.
 */
class BorneDejaPresenteException : public BorneException
{
public:
	BorneDejaPresenteException(const std::string& p_raison);
};

} /* namespace tp */

#endif /* BORNE_DEJA_PRESENTE_EXCEPTION_H_ */
