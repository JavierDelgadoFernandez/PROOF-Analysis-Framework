/**
 * @brief Utility class to deal with strings.
 * @file PAFStringUtil.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-02-12
 */

#pragma once

#include "TString.h"
#include <vector>

/**
 * @class PAFStringUtil
 * @brief Utility class to deal with strings.
 */
class PAFStringUtil 
{
	public:
		/**
		 * Split a string into several strings using a given character.
		 *
		 * If it starts or ends with an empty string, it will be trimmed.
		 *
		 * @param string String to be splitted.
		 * @param cs Character used as delimited.
		 * @return Vector of strings.
		 */
		static std::vector< TString* >* Split(TString* string, const char* cs);
};
