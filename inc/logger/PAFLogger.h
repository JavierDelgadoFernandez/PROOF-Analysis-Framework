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
		void Log(PAFLogLevel loglevel, const char* module, const char* msg);

		/**
		 * Return the current logger behaviour.
		 * 
		 * @return The PAFILogger currently used.
		 */
		PAFILogger* GetLogger();
		
		/**
		 * Set the logger behaviour.
		 * 
		 * @param logger PAFILoger to be used.
		 */
		void SetLogger(PAFILogger* logger);

		
		/**
		 * Return the minimum log level to be registered.
		 */
		PAFLogLevel GetLogLevel();
		
		/**
		 * Set the minimum log level to be registered.
		 * 
		 * @param loglevel Minimum log message level to register.
		 */
		void SetLogLevel(PAFLogLevel loglevel);

		/**
		 * Return the instance of the logger.
		 * 
		 * @return PAFLogger instance.
		 */
		static PAFLogger* GetInstance();
		
	protected:
		/**
		 * Create a PAFLogger.
		 */
		PAFLogger(PAFILogger* logger, PAFLogLevel logLevel);
		
		
	protected:
		/**
		 * Logger behaviour to be used.
		 */
		PAFILogger* fLogger;
		
		/**
		 * Minimum log level to be registered.s
		 */
		PAFLogLevel fLogLevel;
		
		/**
		 * Singleton instance.
		 */
		static PAFLogger* fInstance;
};
