/**
	@brief Header of PAF which will hold PAF variables and PAF relevant methods.  
	@file PAF.h
	@author I. Gonzalez Caballero, J. Delgado Fernandez
	@version 1.0
	@date 2015-01-25
 */

#pragma once

#include "PAFLoggerEnum.h"


/**
 * Log a message with level info.
 * 
 * @param module Name of the module that originates the message.
 * @param msg Message to be logged.
 */
void PAF_INFO(const char* module, const char* msg);

/**
 * Log a message with level debug.
 * 
 * @param module Name of the module that originates the message.
 * @param msg Message to be logged.
 */
void PAF_DEBUG(const char* module, const char* msg);

/**
 * Log a message with level warn.
 * 
 * @param module Name of the module that originates the message.
 * @param msg Message to be logged.
 */
void PAF_WARN(const char* module, const char* msg);

/**
 * Log a message with level error.
 * 
 * @param module Name of the module that originates the message.
 * @param msg Message to be logged.
 */
void PAF_ERROR(const char* module, const char* msg);

/**
 * Log a message with level fatal.
 * 
 * @param module Name of the module that originates the message.
 * @param msg Message to be logged.
 */
void PAF_FATAL(const char* module, const char* msg);


/**
 * Change the minimum level of the messages to be logged.
 * 
 * @param loglevel Minimum new log level.
 */
void PAF_LOG_LEVEL(PAFLogLevel loglevel);
