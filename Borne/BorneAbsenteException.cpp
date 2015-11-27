/**
 * \file BorneAbsenteException.cpp
 * \brief Implementation de la classe BorneAbsenteException
 * \author Pascal Tung
 * \version 1.0
 * \date 15/11/27
 */

#include "BorneAbsenteException.h"

using namespace std;

namespace tp {

/**
 * \brief Constructeur de la classe BorneAbsenteException
 * \param[in] p_raison Le message de l'exception
 */
BorneAbsenteException::BorneAbsenteException(const string& p_raison)
	: BorneException(p_raison)
{
}

} /* namespace tp */
