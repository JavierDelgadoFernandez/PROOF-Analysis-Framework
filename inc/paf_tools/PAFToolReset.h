/**
 * @brief PAF tool class to clean the environment used.
 * @file PAFToolReset.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-04-30
 */

#pragma once

#include "PAFAbstractTool.h"

#include "TFile.h"
#include "TTree.h"

/**
 * @class PAFToolReset
 * @brief PAF tool class to clean the environment used.
 */
class PAFToolReset : public PAFAbstractTool
{
	public:
		/**
		 * Create a PAFToolReset.
		 */
		PAFToolReset();
		
		/**
		 * Delete a PAFToolReset.
		 */
		virtual ~PAFToolReset();

		/**
		 * Execute the concrete tool.
		 * 
		 * @param params The list of input parameters.
		 */
		virtual void ExecuteTool(TList* params);

	protected:
		/**
		 * Name of the tool.
		 */
		static const char* TOOL_NAME;
		
		/**
		 * Message to be used as help.
		 */
		static const char* HELP_MESSAGE;
		
		/**
		 * Example of expression to use the tool.
		 */
		static const char* COMMAND_EXPRESSION;

};
