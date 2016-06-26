/**
 * @brief PAFISettings class which defines several values required by PAF.
 * @file PAFISettings.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-02-07
 */

#pragma once

#include "TObject.h"

#include "TString.h"

/**
 * @class PAFISettings
 * @brief PAFISettings class which defines several values required by PAF.
 */
class PAFISettings : public TObject 
{
	public:
		/**
		 * Default constructor.
		 */
		PAFISettings();

		/**
		 * Destructor.
		 */
		virtual ~PAFISettings();

		/**
		 * Return the PAF installation path.
		 *
		 * @return PAF installation path in the file system.
		 */
		virtual TString* GetPAFPATH() = 0;

		/**
		 * Return the list of folders that contain packages.
		 *
		 * @return A vector with the path in the file system to the directory.
		 */
		virtual std::vector<TString*>* GetPackagesDirectories()= 0;

	ClassDef(PAFISettings, 1);
};
