/**
 * @brief PAF exception to those cases when the command is not a valid expression.
 * @file PAFExceptionCommandExpression.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-04-30
 */

#pragma once

#include "PAFIException.h"

#include "TString.h"

/**
 * @class PAFExceptionCommandExpression
 * @brief PAF exception to those cases when the command is not a valid expression.
 */
class PAFExceptionCommandExpression : public PAFIException
{
	public:
		/**
		 * Create a PAFExceptionCommandExpression.
		 * 
		 * @param toolName Name of the tool that it is failing.
		 */
		PAFExceptionCommandExpression(TString toolName);

		/**
		 * Return the error message.
		 * 
		 * @return TString which contains the error message.
		 */
		virtual TString GetMessage();

	protected:
		/**
		 * Name of the tool which is failing.
		 */
		TString fToolName;
};
