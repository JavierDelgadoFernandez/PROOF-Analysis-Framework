/**
 * @brief Package with users code to compile and load in environments.
 * @file PAFPackageSelector.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-12-04
 */
#pragma once

#include "PAFPackage.h"

/**
 * @class PAFPackageSelector
 * @brief Package with users code to compile and load in environments.
 */
class PAFPackageSelector : public PAFPackage 
{
	public:
		/**
		 * Create a PAFPackageSelector.
		 * 
		 * @param pafsettings Settings that configures the package selector.
		 * @param name Name of the package selector.
		 */
		PAFPackageSelector(PAFISettings* pafsettings = 0, const char* name = 0);

	ClassDef(PAFPackageSelector, 1);
};
