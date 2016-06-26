/**
 * @brief Extension of PAFPROOFCloudEnvironment to work over PROOFCloud environments.
 * @file PAFPROOFCloudEnvironment.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-02-18
 */

#pragma once

#include "PAFPROOFEnvironment.h"

/**
 * @class PAFPROOFCloudEnvironment 
 * @brief Extension of PAFPROOFCloudEnvironment to work over PROOFCloud environments.
 */
class PAFPROOFCloudEnvironment : public PAFPROOFEnvironment 
{
	public:
		/**
		 * Create a PAFPROOFCloudEnvironment.
		 *
		 * @param nSlots Number of workers to be used during the analysis.
		 * @param maxSlavesPerNode Number of processes that will be used per worker.
		 * @param proofRequest Specify if it will execute a request to PROOF.
		 * @param proofServer Server address of PROOF Cloud.
		 * @param proofServerPort Server port of PROOF Cloud.
		 */
		PAFPROOFCloudEnvironment(Int_t nSlots, Int_t maxSlavesPerNode, Bool_t proofRequest, const TString& proofServer, Int_t proofServerPort);

	protected:
		/**
		 * Creates a TProof session using PROOF Cloud.
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
		 * Specify if it will execute a request to PROOF.
		 */
		Int_t fProofRequest;

		/**
		 * Server address of PROOF Cloud.
		 */
		const TString& fProofServer;

		/**
		 * Server port of PROOF Cloud.
		 */
		Int_t fProofServerPort;
};
