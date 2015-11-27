/**
 * \file BorneAbsenteException.h
 * \brief Fichier header de la classe BorneAbsenteException
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/27
 */

#ifndef BORNE_ABSENTE_EXCEPTION_H_
#define BORNE_ABSENTE_EXCEPTION_H_

#include "BorneException.h"

namespace tp {

/**
 * \class BorneAbsenteException
 * \brief Cette classe permet de gérer l’exception de la tentative d’effacement
 * 		d’une Borne absente dans la liste des bornes.
 */
class BorneAbsenteException : public BorneException
{
public:
	BorneAbsenteException(const std::string& p_raison);
};

} /* namespace tp */

#endif /* BORNE_ABSENTE_EXCEPTION_H_ */
