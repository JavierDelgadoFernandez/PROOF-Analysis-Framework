/**
 * @brief Internal PAF class to create the required TSelector in Proof.
 * @file PAFBaseSelector.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-12-04
 */

#pragma once

#include "TTree.h"
#include "TSelector.h"
#include "TString.h"

#include "PAFISelector.h"
#include "PAFVariableContainer.h"

#include "PAF.h"

/**
 * @class PAFBaseSelector
 * @brief Internal PAF class to create the required TSelector in Proof.
 */
class PAFBaseSelector : public TSelector 
{
	public:
		/**
		 * Default constructor.
		 */
		PAFBaseSelector();

		/**
		 * Destructor.
		 */
		virtual ~PAFBaseSelector();

		/**
		 * Return the version of the object.
		 */
		virtual Int_t Version() const;

		/**
		 * Called when a new Tree should be used.
		 *
		 * @param tree New tree to be used.
		 */
		virtual void Init(TTree* tree);

		/**
		 * Called before each worker starts to process.
		 */
		virtual void SlaveBegin(TTree* tree);

		/**
		 * Called once per event.
		 *
		 * @param entry Event that should be processed.
		 */
		virtual Bool_t  Process(Long64_t entry);

		/**
		 * Executed on the client side after the whole process and merge.
		 */
		virtual void Terminate();

		/**
		 * Set the PAFISelector to be used.
		 *
		 * @param pafISelector PAFISelector object to be used.
		 */
		void SetPAFSelector(PAFISelector* pafISelector);

		/**
		 * Return the PAFISelector used.
		 *
		 * @return PAFISelector object.
		 */
		PAFISelector* GetPAFSelector();

		/**
		 * Set the parameters.
		 *
		 * @param selectorParams Parameters.
		 */
		void SetSelectorParams(PAFVariableContainer* selectorParams);

		/**
		 * Return the parameters.
		 *
		 * @return Parameters.
		 */
		PAFVariableContainer* GetSelectorParams();

		/**
		 * Sets the output file name.
		 *
		 * @param outputFile Filename of the output file.
		 */
		void SetOutputFile(const TString& outputFile);

		/**
		 * Return the filename of the output file.
		 *
		 * @return Filename of the output file.
		 */
		TString GetOutputFile();

	protected:
		/**
		 * Tree that is being currently proceesed.
		 */
		TTree* fTree;

		/**
		 * PAFISelector object used to process the data.
		 */
		PAFISelector* fPAFISelector;

		/**
		 * Parameters from the project but also previous selectors.
		 */
		PAFVariableContainer* fSelectorParams;

		/**
		 * Variables contained in the data.
		 */
		PAFVariableContainer* fVariables;//!

		/**
		 * File name output.
		 */
		TString fOutputFile;

	ClassDef(PAFBaseSelector, 1);
};
