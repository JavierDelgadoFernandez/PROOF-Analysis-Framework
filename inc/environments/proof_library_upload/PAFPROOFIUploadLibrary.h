/**
 * @brief Interface to create a strategy pattern to PROOF libraries upload.
 * @file PAFPROOFIUploadLibrary.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-04-15
 */

#pragma once

#include "TProof.h"

#include "PAFLibrary.h"

/**
 * @class PAFPROOFIUploadLibrary
 * @brief Interface to create a strategy pattern to PROOF libraries upload.
 */
class PAFPROOFIUploadLibrary 
{
	public:
		/**
		 * Set the TProof session to use.
		 *
		 * @param session TProof session to be used.
		 */
		virtual void SetSession(TProof* session) = 0;

		/**
		 * Return the TProof session.
		 *
		 * @return TProof session object.
		 */
		virtual TProof* GetSession() = 0;

		/**
		 * Upload a PAFLibrary to upload to the system.
		 *
		 * @param library PAFLibrary object to be uploaded.
		 * @return Success during the operation.
		 */
		virtual bool UploadLibrary(PAFLibrary* library) = 0;
};
