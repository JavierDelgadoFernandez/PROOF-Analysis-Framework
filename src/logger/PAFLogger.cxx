/**
	@brief Logger singleton to facilitate interaction from PAF.
	@file PAFLogger.cxx
	@class PAFLogger
	@author I. Gonzalez Caballero, J. Delgado Fernandez
	@version 1.0
	@date 2015-01-25
 */

#include "PAFLogger.h"

#include "TString.h"

#include "PAFConsoleLogger.h"
#include "PAFStringUtil.h"

PAFLogger* PAFLogger::fInstance = NULL;

PAFLogger::PAFLogger(PAFILogger* logger, PAFLogLevel logLevel)
	: fLogger(logger), fLogLevel(logLevel)
{

}


PAFLogger* PAFLogger::GetInstance()
{
	if (!fInstance)
	{
		PAFILogger* logger = new PAFConsoleLogger();
		PAFLogLevel logLevel = DEBUG;
		fInstance = new PAFLogger(logger, logLevel);
	}
	return fInstance;
}

void PAFLogger::Log(PAFLogLevel loglevel, const char* module, const char* msg)
{
	TString tmsg(msg);
	if(!tmsg.Length())
	{
		return;
	}

	if (loglevel >= PAFLogger::fLogLevel)
	{
		PAFILogger* logger = GetLogger();
		std::vector<TString*>* msgs = PAFStringUtil::Split(&tmsg, "\n");
		for(unsigned int i = 0; i < msgs->size(); i++)
		{
			logger->Log(loglevel, module, msgs->at(i)->Data());
		}
	}
}
