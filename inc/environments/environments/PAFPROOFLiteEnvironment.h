/**
 * @brief Extension of PAFPROOFEnvironment to work over PROOFLite environments.
 * @file PAFPROOFLiteEnvironment.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-12-04
 */

#pragma once

#include "PAFPROOFEnvironment.h"

/**
 * @class PAFPROOFLiteEnvironment
 * @brief Extension of PAFPROOFEnvironment to work over PROOFLite environments.
 */
class PAFPROOFLiteEnvironment : public PAFPROOFEnvironment 
{
	public:
		/**
		 * Create a PAFPROOFEnvironment.
		 *
		 * @param nSlots Number of workers to be used during the analysis.
		 */
		PAFPROOFLiteEnvironment(Int_t nSlots);

	protected:
		/**
		 * Creates a TProof session using PROOF Lite.
		 */
		TProof* doCreateTProof();

	protected:
		/**
		 * Number of workers to be used during the analysis.
		 */
		Int_t fNSlots;
};
