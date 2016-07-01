/**
	@brief Implementation of PAF which will hold PAF variables and PAF relevant methods.  
	@file PAF.cxx
	@class PAF
	@author I. Gonzalez Caballero, J. Delgado Fernandez
	@version 1.0
	@date 2015-01-25
*/

#include "PAF.h"

#include "PAFLogger.h"

#include "TSystem.h"

void PAF_DEBUG(const char* module, const char* msg)
{
	PAFLogger::GetInstance()->Log(DEBUG, module, msg);
}

void PAF_INFO(const char* module, const char* msg)
{
	PAFLogger::GetInstance()->Log(INFO, module, msg);
}

void PAF_WARN(const char* module, const char* msg)
{
	PAFLogger::GetInstance()->Log(WARN, module, msg);
}

void PAF_ERROR(const char* module, const char* msg)
{
	PAFLogger::GetInstance()->Log(ERROR, module, msg);
}

void PAF_FATAL(const char* module, const char* msg)
{
	PAFLogger::GetInstance()->Log(FATAL, module, msg);
	_exit(-1);
}

void PAF_LOG_LEVEL(PAFLogLevel loglevel)
{
	PAFLogger::GetInstance()->SetLogLevel(loglevel);
}
