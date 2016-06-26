/**
 * @brief Logger singleton to facilitate interaction from PAF.
 * @file PAFLogger.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-01-25
 */

#pragma once

#include "PAFILogger.h"

/**
 * @class PAFLogger
 * @brief Logger singleton to facilitate interaction from PAF.
 */
class PAFLogger
{
	public:
		/**
		 * Register a message to the logger.
		 * 
		 * @param level Importance of the message to be logged.
		 * @param module Name of the module that is failing.
		 * @param msg Message to be logged.
		 */
		static void Log(PAFLogLevel loglevel, const char* module, const char* msg);

		/**
		 * Return the current logger behaviour.
		 * 
		 * @return The PAFILogger currently used.
		 */
		static PAFILogger* GetLogger() { return fLogger; }
		
		/**
		 * Set the logger behaviour.
		 * 
		 * @param logger PAFILoger to be used.
		 */
		static void SetLogger(PAFILogger* logger) { fLogger = logger; }

		
		/**
		 * Return the minimum log level to be registered.
		 */
		static PAFLogLevel GetLogLevel() { return fLogLevel; }
		
		/**
		 * Set the minimum log level to be registered.
		 * 
		 * @param loglevel Minimum log message level to register.
		 */
		static void SetLogLevel(PAFLogLevel loglevel) { fLogLevel = loglevel; }

	private:
		/**
		 * Logger behaviour to be used.
		 */
		static PAFILogger* fLogger;
		
		/**
		 * Minimum log level to be registered.s
		 */
		static PAFLogLevel fLogLevel;
};
