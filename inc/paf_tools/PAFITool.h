/**
 * @brief Interface defining a PAFTool behavior.
 * @file PAFITool.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-04-30
 */

#pragma once

#include "TList.h"
#include "TString.h"

/**
 * @class PAFITool
 * @brief Interface defining a PAFTool behavior.
 */
class PAFITool
{
	public:	
		/**
		 * Return the name of the tool.
		 * 
		 * @return The name of the tool as a TString.
		 */
		virtual TString GetToolName() = 0;

		/**
		 * Return the help message.
		 * 
		 * @return The helper message.
		 */
		virtual TString GetHelpMessage() = 0;
		
		/**
		 * Return the example of expression of the tool.
		 * @return The example of use of the tool.
		 */
		virtual TString GetCommandExpression() = 0;

		/**
		 * Execute the concrete tool.
		 * 
		 * @param params The list of input parameters.
		 */
		virtual void ExecuteTool(TList* params) = 0;
};
