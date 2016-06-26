/**
 * @brief PAFLibrary which will contain libraries to load in environments.
 * @file PAFLibrary.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-12-17
 */

#pragma once

#include "TObject.h"

#include "TString.h"

#include "PAFISettings.h"

/**
 * @class PAFLibrary
 * @brief PAFLibrary which will contain libraries to load in environments.
 */
class PAFLibrary : public TObject 
{
	public:
		/**
		 * Create a PAFLibrary.
		 * 
		 * @param pafsettings Settings that configures the library.
		 * @param fileName Filename path.
		 */
                PAFLibrary(PAFISettings* pafsettings = 0, const char* fileName = 0);
		
		/**
		 * Delete a PAFLibrary.
		 */
		virtual ~PAFLibrary();

		/**
		 * Return the library filename (Including the path).
		 * 
		 * @return Library filename (Including the path) as a TString.
		 */
		TString GetFileName() const;
		
		/**
		 * Return the libary filename.
		 * 
		 * @return Library filename.
		 */
		TString GetLibraryName() const;

		/**
		 * Create a PAR file in order to use it directly in ROOT.
		 */
		void CreatePARFile() const;
		
		/**
		 * Return the PAR filename.
		 * 
		 * @return The PAR filename (Including the path).
		 */
		TString GetPARFileName() const;

		/**
		 * Set the settings.
		 * 
		 * @param pafsettings Settings that configures the library.
		 */
		void SetSettings(PAFISettings* pafsettings);
		
		/**
		 * Return the settings.
		 * 
		 * @return PAFISettings object.
		 */
		PAFISettings* GetSettings();

	private:
		/**
		 * Settings that configures the library.
		 */
		PAFISettings* fPAFSettings;
		
		/**
		 * Filename of the library.
		 */
		TString fFileName;

	ClassDef(PAFLibrary, 1);
};
