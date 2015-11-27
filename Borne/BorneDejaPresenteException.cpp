/**
 * \file BorneDejaPresenteException.cpp
 * \brief Implementation de la classe BorneDejaPresenteException
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/27
 */

#include "BorneDejaPresenteException.h"

using namespace std;

namespace tp {

/**
 * \brief Constructeur de la classe BorneDejaPresenteException
 * \param[in] p_raison Le message de l'exception
 */
BorneDejaPresenteException::BorneDejaPresenteException(const string& p_raison)
	: BorneException(p_raison)
{
}

} /* namespace tp */
