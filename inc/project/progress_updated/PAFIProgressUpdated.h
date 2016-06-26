/**
 * @brief Interface to provide the method to call when the analysis progress is updated. 
 * @file PAFIProgressUpdated.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-06-18
 */

#pragma once

#include "TObject.h"

/**
 * @class PAFIProgressUpdated
 * @brief Interface to provide the method to call when the analysis progress is updated. 
 */
class PAFIProgressUpdated : public TObject
{
	public:
		/**
		 * Notification of a progress update.
		 * 
		 * @param total Total number of events (Events already processed plus those ones that are going to be processed in this analysis).
		 * @param processed Already processed events.
		 */
		virtual void ProgressUpdated(Long64_t total, Long64_t processed);

	ClassDef(PAFIProgressUpdated, 1);
};
