/**
 * @brief Interface to create a composite pattern. Implemented by PAFChainSelector and PAFChainItemSelector. 
 * @file PAFISelector.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-12-04
 */

#pragma once

#include "TObject.h"

#include "TList.h"
#include "TSelectorList.h"

#include "PAFVariableContainer.h"

/**
 * @class PAFISelector
 * @brief Interface to create a composite pattern. Implemented by PAFChainSelector and PAFChainItemSelector. 
 */
class PAFISelector : public TObject
{
	public:
		/**
		 * Default constructor.
		 */
		PAFISelector();

		/**
		 * Destructor.
		 */
		virtual ~PAFISelector();
	
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
		virtual void SetStaticData(TList* input, TSelectorList* output, PAFVariableContainer* selectorParams);

		/**
		 * Set the data to the selector that will be changing. It may be called several times during the analysis.
		 *
		 * @param variables Variables that are coming from the input data.
		 */
		virtual void SetDynamicData(PAFVariableContainer* variables);

	ClassDef(PAFISelector, 1);
};
