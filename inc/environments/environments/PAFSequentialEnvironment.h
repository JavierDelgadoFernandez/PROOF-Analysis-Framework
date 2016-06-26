/**
 * @brief Implementation of PAFIExecutionEnvironment to work in sequential mode.
 * @file PAFSequentialEnvironment.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-02-02
 */

#pragma once

#include "PAFIExecutionEnvironment.h"

#include "TTree.h"

/**
 * @class PAFSequentialEnvironment
 * @brief Implementation of PAFIExecutionEnvironment to work in sequential mode.
 */
class PAFSequentialEnvironment : public PAFIExecutionEnvironment 
{
	public:
		/**
		 * Create a PAFSequentialEnvironment.
		 */
		PAFSequentialEnvironment();

		/**
		 * Delete a PAFIExecutionEnvironment/
		 */
		virtual ~PAFSequentialEnvironment();

		/**
		 * Initialise the environment.
		 */
		void Initialise() {}

		/**
		 * Dispose the environment.
		 */
		void Dispose() {}

		/**
		 * Add objects to the analysis input.
		 *
		 * @param obj TObject to be added.
		 */
		virtual void AddInput(TObject* obj);

		/**
		 * Add a histogram that will be updated in real time.
		 *
		 * @param name Name of the histogram that will be updated.
		 */
		virtual void AddFeedback(const char* name);

		/**
		 * Create the object that will be handldling the real time histograms.
		 *
		 * @return TDrawFeedback that draws the histograms.
		 */
		virtual TDrawFeedback* CreateDrawFeedback();

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
		 * Run the selector analysis nentries times.
		 *
		 * @param selector PAFBaseSelector that will be used to analyse the data.
		 * @param nentries Number of times that the InsideLoop will be executed in the PAFISelector.
		 */
		virtual void Process (PAFBaseSelector* selector, Long64_t nentries );

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
		 * Upload a package to the environment.
		 *
		 * @param package Package object to be uploaded.
		 * @return Success during the operation.
		 */
		virtual Bool_t UploadPackage(PAFPackage* package);

		/**
		 * Enable a package in the environment.
		 *
		 * @param package Package object to be enabled.
		 * @return Success during the operation.
		 */
		virtual Bool_t EnablePackage(PAFPackage* package);

		/**
		 * Load a library in the environment.
		 *
		 * @param library Library object to be loaded.
		 * @return Success during the operation.
		 */
		virtual Bool_t LoadLibrary(PAFLibrary* library);

	protected:
		/**
		 * Initialise object function.
		 */
		void InitMembers();

		/**
		 * Calculate the first entry to be calculated of the current tree.
		 *
		 * @param passedEntries Number of entries already processed in previous trees.
		 * @param firstEvent Number of the first event.
		 * @return First entry of the current tree to be processed.
		 */
		Long64_t GetEntriesFrom(Long64_t passedEntries, Long64_t firstEvent);

		/**
		 * Calculate the last entry to be calculated of the current tree.
		 *
		 * @param entriesTree Number the entries that the current tree has.
		 * @param passedEntries Number of entries already processed in previous trees.
		 * @param firstEvent Number of the first event.
		 * @param nEvents Number of events to be processed.
		 * @return Last entry to be calculated of the current tree.
		 */
		Long64_t GetEntriesTo(Long64_t entriesTree, Long64_t passedEntries, Long64_t firstEvent, Long64_t nEvents);

		/**
		 * Calculate the number of entries that the current dataset has.
		 *
		 * @param dataFiles Set of Tree contained inside a files.
		 * @return Total number of entries in the dataFiles.
		 */
		Long64_t GetEntriesTotal(TDSet* dataFiles);

		TTree* GetTree(TDSet* dataFiles, Int_t i);

		/**
		 * Updates the real time histogram.
		 *
		 * @param selector Analysis object that contains the list of outputs.
		 */
		virtual void DrawFeedback(TSelector* selector);

	protected:
		/**
		 * List of inputs for analysis.
		 */
		TList* fInputList;

		/**
		 * List of histograms that are being painted.
		 */
		PAFVariableContainer* fFeedbackCanvas;

		/**
		 * Handles the upload of libraries.
		 */
		PAFIProgressUpdated* fProgressUpdated;
};
