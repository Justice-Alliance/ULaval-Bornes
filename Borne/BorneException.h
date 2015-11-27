/**
 * \file BorneException.h
 * \brief Fichier header de la classe BorneException
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/27
 */

#ifndef BORNEEXCEPTION_H_
#define BORNEEXCEPTION_H_

#include <stdexcept>
#include <string>

namespace tp {

/**
 * \class BorneException
 * \brief Cette classe permet de gérer les exceptions liées aux bornes.
 */
class BorneException : public std::runtime_error
{
public:
	BorneException(const std::string& p_raison);
};

} /* namespace tp */

#endif /* BORNEEXCEPTION_H_ */
