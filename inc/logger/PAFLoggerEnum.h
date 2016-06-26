/**
 * @brief PAFLogLevel enum and string array to make its translations to string.
 * @file PAFLoggerEnum.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-01-25
 */

#pragma once

#pragma GCC diagnostic ignored "-Wunused-variable" //To avoid warnings with PAFLogLevelStrings.

/**
 * Level of logger.
 */
enum PAFLogLevel {
	/**
	 * Used to messages that only inform about the status.
	 */
	INFO,
	/**
	 * Used to useful debug messages.
	 */
	DEBUG, 
	/**
	 * The status or the parameter of an object is not correct, but the execution continues.
	 */
	WARN,
	/**
	 * There is an error, but the framework will try to continue.
	 */
	ERROR, 
	/**
	 * There is an error that avoid the execution.
	 */
	FATAL
};

/**
 * Name the log levels.
 */
static const char* PAFLogLevelStrings[] = { "INFO", "DEBUG", "WARN", "ERROR", "FATAL" };
