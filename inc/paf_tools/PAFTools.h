/**
 * @brief PAF tool executable that holds all paf tools.
 * @file PAFTools.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-04-30
 */

#pragma once

#include "PAFAbstractTool.h"

#include "TList.h"
#include "TString.h"
#include "TApplication.h"

#include <map>

int main(int argc, const char* argv[]);

/**
 * @class PAFTools
 * @brief PAF tool executable that holds all paf tools.
 */
class PAFTools : public PAFAbstractTool
{
	public:
		/**
		 * Create a PAFTools.
		 */ 
		PAFTools();
		
		/**
		 * Delete a PAFTools.
		 */
		virtual ~PAFTools();

		/**
		 * Return the help message.
		 * 
		 * @return The helper message.
		 */
		virtual TString GetHelpMessage();

		/**
		 * Execute the concrete tool using the parameters that come from the terminal.
		 * 
		 * @param argc Number of parameters.
		 * @param argv Array of parameters as strings.
		 */
		void ExecuteTool(int argc, const char* argv[]);
		
		/**
		 * Execute the concrete tool using the parameters that come from the terminal.
		 * 
		 * @param params Parameters parsed into a TList.
		 */
		void ExecuteTool(TList* params);

	protected:
		/**
		 * Map of command tool in order to use it during the parsing.
		 */
		std::map<TString, PAFITool*> fTools;

		/**
		 * Initialise this object.
		 */
		void InitMembers();
		
		/**
		 * Initialise all the tools that compose this tool.
		 */
		void InitTools();

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
