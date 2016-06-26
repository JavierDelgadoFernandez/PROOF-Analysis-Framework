/**
 * @brief Internal PAF class to holds TLeafElements type.
 * @file PAFElementType.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-06-17
 */

#pragma once

#include "PAFAbstractType.h"

/**
 * @class PAFElementType
 * @brief Internal PAF class to holds TLeafElements with pointers to std::vectors.
 */
class PAFElementType : public PAFAbstractType
{
	public:
		/**
		 * Default constructor.
		 */
		PAFElementType();

		/**
		 * Create PAFElementType using a TLeaf object.
		 *
		 * @param leaf TLeaf object.
		 */
		PAFElementType(TLeaf* leaf);

		/**
		 * Delete a PAFElementType.
		 */
		virtual ~PAFElementType();

		/**
		 * Return the pointer to the value.
		 */
		virtual void* GetPointer();

		/**
		 * Return the pointer to the values.
		 *
		 * @param pos Unused parameter.
		 */
		virtual void* GetPointer(Int_t pos);
	
		/**
		 * Calculate the number of items.
		 *
		 * @return Always 1.
		 */
		virtual Int_t GetNData();

	ClassDef(PAFElementType, 1);
};
