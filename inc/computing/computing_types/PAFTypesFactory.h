/**
 * @brief Factory method pattern to create PAF types from TLeafs.
 * @file PAFTypesFactory.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-06-17
 */

#pragma once

#include "TObject.h"

#include "PAFIType.h"
#include "TLeaf.h"

/**
 * @class PAFTypesFactory
 * @brief Factory method pattern to create PAF types from TLeafs.
 */
class PAFTypesFactory : public TObject
{
	public:
		/**
		 * Factory of PAFITypes using TLeaf objects.
		 *
		 * @param leaf TLeaf object used to access the data.
		 * @return PAFIType object ready to be used.
		 */
		PAFIType* GetPAFType(TLeaf* leaf);

	ClassDef(PAFTypesFactory, 1);
};
