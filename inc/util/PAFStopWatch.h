/**
 * @brief Class that allow PAF to take time of some process.
 * @file PAFStopWatch.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-02-22
 */

#pragma once

#include "TList.h"
#include "TString.h"
#include "TStopwatch.h"
#include "TParameter.h"

/**
 * @class PAFStopWatch
 * @brief Class that allow PAF to take time of some process.
 */
class PAFStopWatch 
{
	public:
		/**
		 * Default constructor.
		 */
                PAFStopWatch();

		/**
		 * Destructor.
		 */
		virtual ~PAFStopWatch();

		/**
		 * Start the stopwatch from scratch.
		 */
		virtual void Start();

		/**
		 * Resume a previous couting.
		 */
		virtual void Resume();

		/**
		 * Stop a count.
		 */
		virtual void Stop();

		/**
		 * Take the current time and save it under the given key.
		 *
		 * @param key Name that the time taken will use.
		 */
		void TakeTime(const char* key);

		/**
		 * Return the time of an specific position.
		 *
		 * @param index Position of the time, oredered by time taking.
		 *
		 * @return A tuple containing name, value.
		 */
		TParameter<double>* GetTimeAt(int index);

		/**
		 * Return the whole list of times.
		 *
		 * @return The list tuples with the times.
		 */
		TList* GetTimes();

		/**
		 * Print the times using the logger in level INFO.
		 */
		void PrintTimes();

	protected:
		/**
		 * Initialise the data memebers.
		 */
		void InitMembers();

		/**
		 * Helper function to print a time.
		 */
		void PrintTime(TParameter<double>* time);

	protected:
		/**
		 * Lit of times already taken.
		 */
		TList* fTimes;

		/**
		 * Stopwatch used to count the time.
		 */
		TStopwatch* fWatch;

	ClassDef(PAFStopWatch, 1);
};
