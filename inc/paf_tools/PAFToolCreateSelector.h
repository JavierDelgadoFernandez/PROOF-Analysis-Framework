/**
 * @brief PAF tool class to create the skeleton selector.
 * @file PAFToolCreateSelector.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-05-28
 */

#pragma once

#include "PAFAbstractTool.h"

/**
 * @class PAFToolCreateSelector
 * @brief PAF tool class to create the skeleton selector.
 */
class PAFToolCreateSelector : public PAFAbstractTool
{
	public:
		/**
		 * Create a PAFToolCreateSelector.
		 */
		PAFToolCreateSelector();
		
		/**
		 * Delete a PAFToolCreateSelector.
		 */
		virtual ~PAFToolCreateSelector();

		/**
		 * Execute the concrete tool.
		 * 
		 * @param params The list of input parameters.
		 */
		virtual void ExecuteTool(TList* params);

	protected:
		/**
		 * Create the file using a template.
		 * 
		 * @param iFileName Name of the input file name.
		 * @param oFileName Name of the output file name.
		 * @param from Text to be replaced.
		 * @param to Text used to replace the previous value.
		 */
		void CreateFileTemplated(TString& iFileName, TString& oFileName, TString& from, TString& to);

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

		/**
		 * Environment variable which holds the PAF path to the respositories.
		 */
		static const char* PAFREPOSITORIES_ENV;
		
		/**
		 * Environment variable which holds the path to the PAF installation.
		 */
		static const char* PAFPATH_ENV;
		
		/**
		 * Separator used to split the fields.
		 */
		static const char* FIELDS_SEPARATOR;

		/**
		 * Selector template to use in order to generate the selector.
		 */
		static const char* TEMPLATE_SELECTOR_NAME;
		
		/**
		 * Extension used in the template selector.
		 */
		static const char* TEMPLATE_EXTENSION;
		
		/**
		 * Extension of the resultant header file.
		 */
		static const char* HEADER_EXTENSION;
		
		/**
		 * Extension of the resultant source file.
		 */
		static const char* SOURCE_EXTENSION;
		
		/**
		 * Location of the resultant files.
		 */
		static const char* DIRECTORY;
};
