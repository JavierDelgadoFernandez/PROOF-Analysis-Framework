/**
 * @brief Implementation of PAFILogger with standard output behavior.
 * @file PAFConsoleLogger.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-01-25
 */

#pragma once

#include "PAFILogger.h"

/**
 * @class PAFConsoleLogger
 * @brief Implementation of PAFILogger with standard output behavior.
 */
class PAFConsoleLogger : public PAFILogger
{
	public:
		/**
		 * Register a message to the logger.
		 * 
		 * @param level Importance of the message to be logged.
		 * @param module Name of the module that is failing.
		 * @param msg Message to be logged.
		 */
		virtual void Log(PAFLogLevel level, const char* module, const char* msg);
		
		/**
		 * Empty implementation.
		 */
		virtual void Flush() {}
};
