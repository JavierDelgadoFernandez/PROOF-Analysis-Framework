/**
 * @brief Implementation of PAFIExecutionEnvironment to work over diferents PROOF environments.
 * @file PAFPROOFEnvironment.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-12-04
 */

#pragma once

#include "PAFIExecutionEnvironment.h"

#include "TProof.h"
#include "PAFPROOFIUploadLibrary.h"

/**
 * @class PAFPROOFEnvironment
 * @brief Implementation of PAFIExecutionEnvironment to work over diferents PROOF environments.
 */
class PAFPROOFEnvironment : public PAFIExecutionEnvironment 
{
	public:
		/**
		 * Create a PAFPROOFEnvironment.
		 */
		PAFPROOFEnvironment();

		/**
		 * Delete a PAFPROOFEnvironment.
		 */
		virtual ~PAFPROOFEnvironment();

		/**
		 * Initialise the environment.
		 */
		void Initialise();

		/**
		 * Dispose the environment.
		 */
		void Dispose();

		/**
		 * Add objects to the analysis input.
		 *
		 * @param obj TObject to be added.
		 */
		void AddInput(TObject* obj);

		/**
		 * Add a histogram that will be updated in real time.
		 *
		 * @param name Name of the histogram that will be updated.
		 */
		void AddFeedback(const char* name);

		/**
		 * Create the object that will be handldling the real time histograms.
		 *
		 * @return TDrawFeedback that draws the histograms.
		 */
		TDrawFeedback* CreateDrawFeedback();
		
		/**
		 * Set the object that handles the progress reporting.
		 *
		 * @param progressUpdated Handler of the progress reporting.
		 */
		virtual void SetProgressUpdated(PAFIProgressUpdated* progressUpdated);

		/**
		 * Get the object that handles the progress reporting.
		 *
		 * @return Handler of the progress reporting.
		 */
		virtual PAFIProgressUpdated* GetProgressUpdated();

		/**
		 * Upload a package to the environment.
		 *
		 * @param package Package object to be uploaded.
		 * @return Success during the operation.
		 */
		Bool_t UploadPackage(PAFPackage* package);

		/**
		 * Enable a package in the environment.
		 *
		 * @param package Package object to be enabled.
		 * @return Success during the operation.
		 */
		Bool_t EnablePackage(PAFPackage* package);

		/**
		 * Load a library in the environment.
		 *
		 * @param library Library object to be loaded.
		 * @return Success during the operation.
		 */
		Bool_t LoadLibrary(PAFLibrary* library);

		/**
		 * Run the selector analysis nentries times.
		 *
		 * @param selector PAFBaseSelector that will be used to analyse the data.
		 * @param nentries Number of times that the InsideLoop will be executed in the PAFISelector.
		 */
		virtual void Process(PAFBaseSelector* selector, Long64_t nentries);

		/**
		 * Run the selector analysis using the data coming from the dataFiles.
		 *
		 * @param selector PAFBaseSelector that will be used to analyse the data.
		 * @param dataFiles Data files containing all the variables.
		 * @param firstEvent Starting event to analyse.
		 * @param nEvents Number of events that will be analyzed.
		 */
		virtual void Process(PAFBaseSelector* selector, TDSet* dataFiles, Long64_t firstEvent, Long64_t nEvents);

		/**
		 * Set the object that handles the upload of libraries to the environment.
		 *
		 * @param proofUploadLibrary PAFPROOFIUploadLibrary object that handles the upload.
		 */
		void SetPROOFUpload(PAFPROOFIUploadLibrary* proofUploadLibrary);

		/**
		 * Get the object that handles the upload of libraries to the environment.
		 *
		 * @return PAFPROOFIUploadLibrary object that handles the upload.
		 */
		PAFPROOFIUploadLibrary* GetPROOFUpload();

	protected:
		/**
		 * Initialise object function.
		 */
		void InitMembers();

		/**
		 * Template method to create TProof sessions.
		 */
		virtual TProof* doCreateTProof() = 0;

		/**
		 * Load the libPAF.so file in the environment.
		 */
		virtual void LoadPAF();

	protected:
		/**
		 * TProof session.
		 */
		TProof* fSession;

		/**
		 * Handles the upload of libraries.
		 */
		PAFPROOFIUploadLibrary* fPROOFUploadLibrary;
};
