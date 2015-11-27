/**
 * \file BorneException.cpp
 * \brief Implementation de la classe BorneException
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/27
 */

#include "BorneException.h"

using namespace std;

namespace tp {

/**
 * \brief Constructeur de la classe de base BorneException
 * \param[in] p_raison Le message de l'exception
 */
BorneException::BorneException(const string& p_raison)
	: runtime_error(p_raison)
{
}

} /* namespace tp */
