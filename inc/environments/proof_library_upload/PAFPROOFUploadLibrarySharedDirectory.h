/**
 * @brief PROOF Uplod library using a shared file system.
 * @file PAFPROOFUploadLibrarySharedDirectory.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-04-15
 */

#pragma once

#include "PAFPROOFUploadLibraryAbstract.h"

/**
 * @class PAFPROOFUploadLibrarySharedDirectory
 * @brief PROOF Uplod library using a shared file system.
 */
class PAFPROOFUploadLibrarySharedDirectory : public PAFPROOFUploadLibraryAbstract 
{
	public:
		/**
		 * Create a PAFPROOFUploadLibrarySharedDirectory.
		 */
		PAFPROOFUploadLibrarySharedDirectory();

		/**
		 * Delete a PAFPROOFUploadLibrarySharedDirectory.
		 */
		virtual ~PAFPROOFUploadLibrarySharedDirectory();

		/**
		 * Upload a PAFLibrary to upload to the system using a filesystem shared directory.
		 *
		 * @param library PAFLibrary object to be uploaded.
		 * @return Success during the operation.
		 */
		bool UploadLibrary(PAFLibrary* library);
};
