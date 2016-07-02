/**
 * @brief Abstract class to implement the common behaviour of PAFPROOFIUploadLibrary.
 * @file PAFPROOFUploadLibraryAbstract.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2016-07-02
 */

#pragma once

#include "PAFPROOFIUploadLibrary.h"

/**
 * @class PAFPROOFUploadLibraryAbstract
 * @brief Abstract class to implement the common behaviour of PAFPROOFIUploadLibrary.
 */

class PAFPROOFUploadLibraryAbstract : public PAFPROOFIUploadLibrary
{
	public:
		/**
		 * Create a PAFPROOFUploadLibraryAbstract.
		 */
		PAFPROOFUploadLibraryAbstract();
		
		/**
		 * Delete a PAFPROOFUploadLibraryAbstract.
		 */
		virtual ~PAFPROOFUploadLibraryAbstract();
		
		/**
		 * Set the TProof session to use.
		 *
		 * @param session TProof session to be used.
		 */
		virtual void SetSession(TProof* session);

		/**
		 * Return the TProof session.
		 *
		 * @return TProof session object.
		 */
		virtual TProof* GetSession();
	
	protected:
		/**
		 * TProof session used.
		 */
		TProof* fSession;
};
