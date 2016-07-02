/**
 * @brief PAFEnvironmentVariableSettings class which gets the EnvironmentVariables.
 * @file PAFEnvironmentVariableSettings.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-02-07
 */

#pragma once

#include "PAFISettings.h"

#include "TString.h"

/**
 * @class PAFEnvironmentVariableSettings
 * @brief PAFEnvironmentVariableSettings class which gets the EnvironmentVariables.
 */
class PAFEnvironmentVariableSettings : public PAFISettings 
{
	public:
		/**
		 * Default constructor.
		 */
		PAFEnvironmentVariableSettings();

		/**
		 * Destructor.
		 */
		virtual ~PAFEnvironmentVariableSettings();

		/**
		 * Return the PAF installation path using the environment variables.
		 *
		 * @return PAF installation path in the file system.
		 */
		virtual TString* GetPAFPATH();

		/**
		 * Return the list of folders that contain packages using the environment variables.
		 *
		 * @return A vector with the path in the file system to the directory.
		 */
		virtual std::vector<TString*>* GetPackagesDirectories();

	protected:
		TString* GetEnvironmentVariable(const char* variable);

	protected:
		/**
		 * PAF installation path in the file system/
		 *
		 * Used to cache the result.
		 */
		TString* fPAFPATH;

		/**
		 * A vector with the path in the file system to the directory.
		 *
		 * Used to cache the results.
		 */
		std::vector<TString*>*	fPackagesDirectories;

	ClassDef(PAFISettings, 1);
};
