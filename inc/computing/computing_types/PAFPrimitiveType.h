/**
 * @brief Internal PAF class to holds ROOT types (Float_t, Double_t...) TLeafs.
 * @file PAFPrimitiveType.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-06-17
 */

#pragma once

#include "PAFAbstractType.h"

/**
 * @class PAFPrimitiveType
 * @brief Internal PAF class to holds ROOT types (Float_t, Double_t...) TLeafs.
 */
template <class T>
class PAFPrimitiveType : public PAFAbstractType
{
	public:
		/**
		 * Default constructor.
		 */
		PAFPrimitiveType();

		/**
		 * Create PAFPrimitiveType using a TLeaf object.
		 */
		PAFPrimitiveType(TLeaf* leaf);

		/**
		 * Delete a PAFPrimitiveType.
		 */
		virtual ~PAFPrimitiveType();

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

	ClassDef(PAFPrimitiveType<T>, 1);
};

template <class T>
PAFPrimitiveType<T>::PAFPrimitiveType()
	: PAFAbstractType()
{

}

template <class T>
PAFPrimitiveType<T>::PAFPrimitiveType(TLeaf* leaf)
	: PAFAbstractType(leaf)
{

}

template <class T>
PAFPrimitiveType<T>::~PAFPrimitiveType()
{

}

template <class T>
void* PAFPrimitiveType<T>::GetPointer()
{
	EnableBranch();
	T* values = (T*)fLeaf->GetValuePointer();
	return &values[0];
}

template <class T>
void* PAFPrimitiveType<T>::GetPointer(Int_t pos)
{
	EnableBranch();
	T* values = (T*)fLeaf->GetValuePointer();
	return &values[pos];
}
