/**
 * @brief Internal PAF class to abstract some common implemtation of concretes PAFITypes.
 * @file PAFAbstractType.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-06-17
 */

#pragma once

#include "PAFIType.h"

/**
 * @class PAFAbstractType
 * @brief Internal PAF class to abstract some common implemtation of concretes PAFITypes.
 */
class PAFAbstractType : public PAFIType
{
	public:
		/**
		 * Default constructor.
		 */
		PAFAbstractType();

		/**
		 * Constructor expecting a TLeaf.
		 *
		 * @param leaf TLeaf object holding the values.
		 */
		PAFAbstractType(TLeaf* leaf);

		/**
		 * Destructor.
		 */
		virtual ~PAFAbstractType();

		/**
		 * Set the TLeaf object.
		 *
		 * @param leaf TLeaf object holding the values.
		 */
		virtual void SetTLeaf(TLeaf* leaf);

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
		
		/**
		 * Enable the branch in order to be able to read the values.
		 */
		virtual void EnableBranch();

	protected:
		/**
		 * TLeaf object that contains the values.
		 */
		TLeaf* fLeaf;

	ClassDef(PAFAbstractType, 1);
};
