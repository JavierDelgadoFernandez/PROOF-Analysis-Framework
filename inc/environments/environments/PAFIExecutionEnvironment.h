/**
 * @brief Interface to create strategy pattern with diferentes executions environments.
 * @file PAFIExecutionEnvironment.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-12-04
 */

#pragma once

#include "TObject.h"
#include "TDSet.h"
#include "TDrawFeedback.h"

#include "PAFBaseSelector.h"
#include "PAFPackage.h"
#include "PAFLibrary.h"
#include "PAFIProgressUpdated.h"

/**
 * @class PAFIExecutionEnvironment
 * @brief Interface to create strategy pattern with diferentes executions environments.
 */
class PAFIExecutionEnvironment 
{
	public:
		/**
		 * Initialise the environment.
		 */
		virtual void Initialise() = 0;

		/**
		 * Dispose the environment.
		 */
		virtual void Dispose() = 0;

		/**
		 * Add objects to the analysis input.
		 *
		 * @param obj TObject to be added.
		 */
		virtual void AddInput(TObject* obj) = 0;

		/**
		 * Add a histogram that will be updated in real time.
		 *
		 * @param name Name of the histogram that will be updated.
		 */
		virtual void AddFeedback(const char* name) = 0;

		/**
		 * Create the object that will be handldling the real time histograms.
		 *
		 * @return TDrawFeedback that draws the histograms.
		 */
		virtual TDrawFeedback* CreateDrawFeedback() = 0;

		/**
		 * Set the object that handles the progress reporting.
		 *
		 * @param progressUpdated Handler of the progress reporting.
		 */
		virtual void SetProgressUpdated(PAFIProgressUpdated* progressUpdated) = 0;

		/**
		 * Get the object that handles the progress reporting.
		 *
		 * @return Handler of the progress reporting.
		 */
		virtual PAFIProgressUpdated* GetProgressUpdated() = 0;

		/**
		 * Upload a package to the environment.
		 *
		 * @param package Package object to be uploaded.
		 * @return Success during the operation.
		 */
		virtual Bool_t UploadPackage(PAFPackage* package) = 0;

		/**
		 * Enable a package in the environment.
		 *
		 * @param package Package object to be enabled.
		 * @return Success during the operation.
		 */
		virtual Bool_t EnablePackage(PAFPackage* package) = 0;

		/**
		 * Load a library in the environment.
		 *
		 * @param library Library object to be loaded.
		 * @return Success during the operation.
		 */
		virtual Bool_t LoadLibrary(PAFLibrary* library) = 0;

		/**
		 * Run the selector analysis nentries times.
		 *
		 * @param selector PAFBaseSelector that will be used to analyse the data.
		 * @param nentries Number of times that the InsideLoop will be executed in the PAFISelector.
		 */
		virtual void Process(PAFBaseSelector* selector, Long64_t nentries) = 0;

		/**
		 * Run the selector analysis using the data coming from the dataFiles.
		 *
		 * @param selector PAFBaseSelector that will be used to analyse the data.
		 * @param dataFiles Data files containing all the variables.
		 * @param firstEvent Starting event to analyse.
		 * @param nEvents Number of events that will be analyzed.
		 */
		virtual void Process(PAFBaseSelector* selector, TDSet* dataFiles, Long64_t firstEvent, Long64_t nEvents) = 0;
};
