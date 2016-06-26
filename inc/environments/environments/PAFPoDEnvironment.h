/**
 * @brief Extension of PAFPROOFEnvironment to work over PoD environments.
 * @file PAFPoDEnvironment.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-12-04
 */

#pragma once

#include "PAFPROOFEnvironment.h"

/**
 * @class PAFPoDEnvironment
 * @brief Extension of PAFPROOFEnvironment to work over PoD environments.
 */
class PAFPoDEnvironment : public PAFPROOFEnvironment 
{
	public:
		/**
		 * Create a PAFPoDEnvironment.
		 *
		 * @param nSlots Number of workers to be used during the analysis.
		 * @param maxSlavesPerNode Number of processes that will be used per worker.
		 * @param timeOut Timeout to get a connection with PoD cluster.
		 */
		PAFPoDEnvironment(Int_t nSlots = 10, Int_t maxSlavesPerNode=9999, Int_t timeOut = 60);

		/**
		 * Delete a PAFPoDEnvironment.
		 */
		virtual ~PAFPoDEnvironment();

	protected:
		/**
		 * Creates a TProof session using PoD.
		 */
		TProof* doCreateTProof();

	protected:
		/**
		 * Number of workers to be used during the analysis.
		 */
		Int_t fNSlots;

		/**
		 * Number of processes that will be used per worker.
		 */
		Int_t fMaxSlavesPerNode;

		/**
		 * Timeout to get a connection with PoD cluster.
		 */
		Int_t fTimeOut;
};
