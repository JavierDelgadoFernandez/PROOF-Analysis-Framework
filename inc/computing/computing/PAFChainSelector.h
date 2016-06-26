/**
 * @brief Class which allows us to create a chain of selectors. 
 * @file PAFChainSelector.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-12-04
 */

#pragma once

#include "PAFISelector.h"

/**
 * @class PAFChainSelector
 * @brief Class which allows us to create a chain of selectors. 
 */
class PAFChainSelector : public PAFISelector
{
	public:
		/**
		 * Default constructor.
		 */
		PAFChainSelector();

		/**
		 * Constructor expecting the list of selectors.
		 *
		 * @param selectors List of PAFISelector to use.
		 */
		PAFChainSelector(std::vector<PAFISelector*>* selectors);

		/**
		 * Destructor.
		 */
		virtual ~PAFChainSelector();

		/**
		 * Initialise method called only once per worker.
		 */
		virtual void Initialise();

		/**
		 * InitialiseParameters called after Initialise and only once per worker.
		 */
		virtual void InitialiseParameters();

		/**
		 * InsideLoop method, called once per event and after the initialise methods.
		 */
		virtual void InsideLoop();

		/**
		 * Summary method, runs after the whole process ends and it is executed on the client node. Used to print the results.
		 */
		virtual void Summary();


		/**
		 * Set the data to the selector that it is not going to change during the whole analysis in each worker.
		 *
		 * @param input List of inputs that come from the project.
		 * @param output List of items where the selector will leave the results.
		 * @param selectorParams Input variables set on the project.
		 */
		virtual void SetStaticData(TList* fInput, TSelectorList* fOutput, PAFVariableContainer* selectorParams);

		/**
		 * Set the data to the selector that will be changing. It may be called several times during the analysis.
		 *
		 * @param variables Variables that are coming from the input data.
		 */
		virtual void SetDynamicData(PAFVariableContainer* variables);

	private:
		/**
		 * List of selectors.
		 */
		std::vector<PAFISelector*> fSelectors;

	ClassDef(PAFChainSelector, 1);
};
