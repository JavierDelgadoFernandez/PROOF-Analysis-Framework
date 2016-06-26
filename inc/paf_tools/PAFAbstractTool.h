/**
 * @brief Abstract class to provides a default implementation of PAFItool.
 * @file PAFAbstractTool.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-04-30
 */

#pragma once

#include "PAFITool.h"

#include "Rtypes.h"

/**
 * @class PAFAbstractTool
 * @brief Abstract class to provides a default implementation of PAFItool.
 */
class PAFAbstractTool : public PAFITool
{
	public:
		/**
		 * Create a PAFAbstractTool.
		 * @param toolName Name of the tool.
		 * @param helpMessage Message to be showed as help.
		 * @param commandExpression Example of expression of the tool.
		 */
		PAFAbstractTool(TString toolName, TString helpMessage, TString commandExpression);

		/**
		 * Return the name of the tool.
		 * 
		 * @return The name of the tool as a TString.
		 */
		virtual TString GetToolName();
		
		/**
		 * Return the help message.
		 * 
		 * @return The helper message.
		 */
		virtual TString GetHelpMessage();
		
		/**
		 * Return the example of expression of the tool.
		 * 
		 * @return The example of use of the tool.
		 */
		virtual TString GetCommandExpression();

	protected:
		/**
		 * Exit the tool showing a message.
		 * 
		 * @param message Message that will be shown to the user.
		 * @param error Error code to return.
		 */
		virtual void Exit(const TString& message, Int_t error = -1);
		
		/**
		 * Return the parameter in a certain position.
		 * 
		 * @param params List of all input parameters.
		 * @param i Position of the parameter to retrieve.
		 * @return The parameter of that position.
		 */
		virtual TString* GetParam(TList* params, Int_t i);
		
		/**
		 * Return the parameter that comes with a given name.
		 * 
		 * @param params List of all input parameters.
		 * @param keys Key that is used to identify the parameter.
		 * @param keyl Alternative key used to identify the parameter.
		 * @return The value of the parameter.
		 */
		virtual TString* GetParam(TList* params, const TString& keys, const TString& keyl);
		
		/**
		 * Check if a parameter exists.
		 * 
		 * @param params List of all input parameters.
		 * @param keys Key that is used to identify the parameter.
		 * @param keyl Alternative key used to identify the parameter.
		 * @return True if the parameter exists.
		 */
		virtual Bool_t ExistsParam(TList* params, const TString& keys, const TString& keyl);
		
		/**
		 * Print a message in the terminal.
		 * 
		 * @param message Message to be shown in the terminal.
		 */
		virtual void PrintMessage(TString& message);
		
		
		/**
		 * Print a message in the terminal.
		 * 
		 * @param message Message to be shown in the terminal.
		 */
		virtual void PrintMessage(const char* message);

	protected:
		/**
		 * Name of the tool.
		 */
		TString fToolName;
		
		/**
		 * Message to be shown as help.
		 */
		TString fHelpMessage;
		
		/**
		 * Example of expression of the tool.
		 */
		TString fCommandExpression;
};
