/**
 * @brief Extension of PAFPROOFClusterEnvironment to work over PROOFCluster environments.
 * @file PAFPROOFClusterEnvironment.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-02-18
 */

#pragma once

#include "PAFPROOFEnvironment.h"

/**
 * @class PAFPROOFClusterEnvironment
 * @brief Extension of PAFPROOFClusterEnvironment to work over PROOFCluster environments.
 */
class PAFPROOFClusterEnvironment : public PAFPROOFEnvironment 
{
	public:
		/**
		 * Create a PAFPROOFClusterEnvironment.
		 *
		 * @param nSlots Number of workers to be used during the analysis.
		 * @param maxSlavesPerNode Number of processes that will be used per worker.
		 */
		PAFPROOFClusterEnvironment(Int_t nSlots = 10, Int_t maxSlavesPerNode = 9999);

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
};
