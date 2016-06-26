/**
 * @brief Class to create a PAFProjectGeneric which should be configured (although it has some default values) and launched to get results. 
 * @file PAFProjectGeneric.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-04-21
 */

#pragma once

#include "PAFAbstractProject.h"

/**
 * @class PAFProjectGeneric
 * @brief Class to create a PAFProjectGeneric which should be configured (although it has some default values) and launched to get results. 
 */
class PAFProjectGeneric : public PAFAbstractProject
{
	public:
		/**
		 * Create a PAFProjectGeneric.
		 */
		PAFProjectGeneric();
		
		/**
		 * Create a PAFProjectGeneric.
		 * 
		 * @param nentries Number of times that the InsideLoop should be executed.
		 */
		PAFProjectGeneric(Long64_t nentries);
		
		/**
		 * Create a PAFProjectGeneric.
		 * 
		 * @param executionEnvironment Execution environment to be used.
		 */
		PAFProjectGeneric(PAFIExecutionEnvironment* executionEnvironment);
		
		/**
		 * Create a PAFProjectGeneric.
		 * 
		 * @param executionEnvironment Execution environment to be used.
		 * @param nentries Number of times that the InsideLoop should be executed.
		 */
		PAFProjectGeneric(PAFIExecutionEnvironment* executionEnvironment, Long64_t nentries);
		
		/**
		 * Delete a PAFProjectGeneric.
		 */
		virtual ~PAFProjectGeneric();

		/**
		 * Set the number of times that the InsideLoop should be executed.
		 * 
		 * @param nentries Number of times that the InsideLoop should be executed.
		 */
		void SetNEntries(Long64_t nentries);
		
		/**
		 * Return the number of times that the InsideLoop should be executed.
		 * 
		 * @return Number of times that the InsideLoop should be executed.
		 */
		Long64_t GetNEntries();

		/**
		 * Execute the analysis using the given selector.
		 * 
		 * @param selector Selector to be used.
		 */
		void doRun(PAFBaseSelector* selector);      

	protected:
		/**
		 * Number of times that the InsideLoop should be executed.
		 */
		Long64_t fNEntries;

	ClassDef(PAFProjectGeneric, 1);
};
