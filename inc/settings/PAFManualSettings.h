/**
 * @brief PAFManualSettings class which holds the variables the user specifies.
 * @file PAFManualSettings.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-06-03
 */

#pragma once

#include "PAFISettings.h"

#include "TString.h"

/**
 * @class PAFManualSettings
 * @brief PAFManualSettings class which holds the variables the user specifies.
 */
class PAFManualSettings : public PAFISettings 
{
	public:
		/**
		 * Constructor expecting the PAFPATH and the directories.
		 *
		 * @param pafPath PAF installation path in the file system.
		 * @param packagesDirectories A vector with the path in the file system to the directory.
		 */
		PAFManualSettings(TString* pafPath, std::vector<TString*>* packagesDirectories);

		/**
		 * Return the PAF installation path.
		 *
		 * @return PAF installation path in the file system.
		 */
		virtual TString* GetPAFPATH();

		/**
		 * Return the list of folders that contain packages.
		 *
		 * @return A vector with the path in the file system to the directory.
		 */
		virtual std::vector< TString* >* GetPackagesDirectories();

	protected:
		/**
		 * PAF installation path in the file system.
		 */
		TString fPAFPath;

		/**
		 * A vector with the path in the file system to the directory.
		 */
		std::vector<TString*> fPackagesDirectories;

	ClassDef(PAFManualSettings, 1);
};
