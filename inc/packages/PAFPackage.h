/**
 * @brief Generic PAFPackage which will contain items to load in environments.
 * @file PAFPackage.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-12-04
 */

#pragma once

#include "TObject.h"

#include "TString.h"
#include "PAFISettings.h"

/**
 * @class PAFPackage
 * @brief Generic PAFPackage which will contain items to load in environments.
 */
class PAFPackage : public TObject 
{
	public:
		/**
		 * Default constructor.
		 */
		PAFPackage();
		
		/**
		 * Create a PAFPackage object.
		 * 
		 * @param pafsettings Settings object to be used.
		 * @param name Name of the package.
		 */
		PAFPackage(PAFISettings* pafsettings, const char* name);
		
		/**
		 * Delete a PAFPackage.
		 */
		virtual ~PAFPackage();

		/**
		 * Prepares the package to be compiled.
		 */
		void PreparePackage() const;
		
		/**
		 * Create the PAR file with all the content of the current folder.
		 */
		void CreateParFile() const;
		
		/**
		 * Compile the package as a shared object.
		 */
		void CompileAsLibrary() const;

		/**
		 * Set the name of the package.
		 * 
		 * @param name Name of the package.
		 */
		void SetName(const char* name);
		
		/**
		 * Return the name of the package.
		 * 
		 * @return Name of the package.
		 */
		virtual const char* GetName() const;

		/**
		 * Return the full library filename (Contains also the path to the file).
		 */
		TString GetLibraryFileName() const;
		
		/**
		 * Return the full PAR filename (Contains also the path to the file).
		 */
		TString GetParFileName() const;

		/**
		 * Set the setting.
		 * 
		 * @param pafsettings PAFISettings object.
		 */
		void SetSettings(PAFISettings* pafsettings);
		
		/**
		 * Return the settings.
		 * 
		 * @return PAFISettings object.
		 */
		PAFISettings* GetSettings();

	protected:
		/**
		 * Template method to generate the command which prepares the package.
		 * 
		 * @return TString which specify the command used to generate the package.
		 */
		virtual TString GetPreparePackageCommand() const;

		/**
		 * Get the directory that contains the package.
		 * 
		 * @return TString with the full path to the directory which contains the file.
		 */
		TString GetPackageDir() const;
		
		/**
		 * Get the directory that will be used to store the temporal files.
		 * 
		 * @return TString with the full path to the directory used to work with the package.
		 */
		TString GetPackagesDir() const;

	protected:
		/**
		 * Settings that configures the package.
		 */
		PAFISettings* fPAFSettings;
		
		/**
		 * Name of the package.
		 */
		TString fName;

	ClassDef(PAFPackage, 1);
};
