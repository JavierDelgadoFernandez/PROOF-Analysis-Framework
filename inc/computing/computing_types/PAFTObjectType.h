/**
 * @brief Internal PAF class to holds TObjects based on TLeafObject.
 * @file PAFTObjectType.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-06-17
 */

#pragma once

#include "PAFAbstractType.h"

/**
 * @class PAFTObjectType
 * @brief Internal PAF class to holds TObjects based on TLeafObject.
 */
class PAFTObjectType : public PAFAbstractType
{
	public:
		/**
		 * Default constructor.
		 */
		PAFTObjectType();

		/**
		 * Create a PAFTObjectType using a TLeaf object.
		 */
		PAFTObjectType(TLeaf* leaf);

		/**
		 * Delete a PAFTObjectType.
		 */
		virtual ~PAFTObjectType();

		/**
		 * Return the pointer to the value.
		 */
		virtual void* GetPointer();

		/**
		 * Return the pointer to the value.
		 *
		 * @param pos Unused parameter.
		 */
		virtual void* GetPointer(Int_t pos);

	ClassDef(PAFTObjectType, 1);
};
