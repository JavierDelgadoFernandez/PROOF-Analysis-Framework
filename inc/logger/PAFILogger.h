/**
 * @brief Interface to implement different behaviours of loggers. 
 * @file PAFILogger.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-01-25
 */

#pragma once

#include "PAFLoggerEnum.h"

/**
 * @class PAFILogger
 * @brief Interface to implement different behaviours of loggers. 
 */
class PAFILogger
{
	public:
		/**
		 * Register a message to the logger.
		 * 
		 * @param level Importance of the message to be logged.
		 * @param module Name of the module that is failing.
		 * @param msg Message to be logged.
		 */
		virtual void Log(PAFLogLevel level, const char* module, const char* msg) = 0;
		
		/**
		 * Finalize the logger session.
		 */
		virtual void Flush() = 0;
};
