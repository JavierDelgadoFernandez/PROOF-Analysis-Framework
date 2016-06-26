/**
 * @brief Implementation of PAFIProgressUpdated which uses the logger to show the information.
 * @file PAFProgressUpdatedLogger.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-06-18
 */

#pragma once

#include "PAFIProgressUpdated.h"

/**
 * @class PAFProgressUpdatedLogger
 * @brief Implementation of PAFIProgressUpdated which uses the logger to show the information.
 */
class PAFProgressUpdatedLogger : public PAFIProgressUpdated
{
	public:
		/**
		 * Notification of a progress update.
		 * 
		 * @param total Total number of events (Events already processed plus those ones that are going to be processed in this analysis).
		 * @param processed Already processed events.
		 */
		void ProgressUpdated(Long64_t total, Long64_t processed);

	ClassDef(PAFProgressUpdatedLogger, 1);
};
