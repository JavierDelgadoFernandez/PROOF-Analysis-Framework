/**
 * @brief Internal PAF class to hold TLeafs of a TTree in order to be used by PAF.
 * @file PAFIType.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-06-17
 */

#pragma once

#include "TObject.h"

#include "TLeaf.h"

/**
 * @class PAFIType
 * @brief Internal PAF class to hold TLeafs of a TTree in order to be used by PAF.
 */
class PAFIType : public TObject
{
	public:
		/**
		 * Return the pointer to the values.
		 */
		virtual void* GetPointer();

		/**
		 * Return the pointer to the value in position pos.
		 *
		 * @param pos Position of the item.
		 */
		virtual void* GetPointer(Int_t pos);

		/**
		 * Return the TLeaf object.
		 *
		 * @return TLeaf object.
		 */
		virtual TLeaf* GetLeaf();
		
		/**
		 * Calculates the number of items that the value contains.
		 *
		 * @return The number of items that the value contains.
		 */
		virtual Int_t GetNData();

	ClassDef(PAFIType, 1);
};
