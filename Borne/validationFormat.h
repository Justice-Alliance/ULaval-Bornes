/*
 * validationFormat.h
 *
 *  Created on: 2015-09-19
 *      Author: etudiant
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include <string>

namespace util
{
	bool valideLigneGEOJSON (std::string& p_ligne, std::ostringstream& p_parametres);
	bool valideLigneCVS (std::string& p_ligne, std::ostringstream& p_parametres);
	bool validerGeom(const std::string& p_geom);
	bool validerPointCardinal(const std::string& p_cardinalite);
} /* namespace util */

#endif /* VALIDATIONFORMAT_H_ */
