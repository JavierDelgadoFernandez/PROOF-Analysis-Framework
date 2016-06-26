/**
 * @brief PAF exception interface.
 * @file PAFIException.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-04-30
 */

#pragma once

#include "TString.h"

/**
 * @class PAFIException
 * @brief PAF exception interface.
 */
class PAFIException
{
	public:
		/**
		 * Return the error message.
		 * 
		 * @return TString which contains the error message.
		 */
		virtual TString GetMessage() = 0;
};
