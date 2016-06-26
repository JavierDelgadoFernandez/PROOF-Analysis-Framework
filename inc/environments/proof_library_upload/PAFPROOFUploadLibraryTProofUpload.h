/**
 * @brief PROOF Uplod library using TProof package mechanism.
 * @file PAFPROOFUploadLibraryTProofUpload.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-04-15
 */

#pragma once

#include "PAFPROOFIUploadLibrary.h"

/**
 * @class PAFPROOFUploadLibraryTProofUpload
 * @brief PROOF Uplod library using TProof package mechanism.
 */
class PAFPROOFUploadLibraryTProofUpload : public PAFPROOFIUploadLibrary 
{
	public:
		/**
		 * Create a PAFPROOFUploadLibraryTProofUpload.
		 */
		PAFPROOFUploadLibraryTProofUpload();

		/**
		 * Delete a PAFPROOFUploadLibraryTProofUpload.
		 */
		virtual ~PAFPROOFUploadLibraryTProofUpload();

		/**
		 * Upload a PAFLibrary to upload to the system usint the ROOT protocol.
		 *
		 * @param library PAFLibrary object to be uploaded.
		 * @return Success during the operation.
		 */
		bool UploadLibrary(PAFLibrary* library);
};
