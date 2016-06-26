/**
 * @brief Internal PAF class to holds ROOT arrays types (Float_t, Double_t...) TLeafs.
 * @file PAFArrayPrimitiveType.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-06-17
 */

#pragma once

#include "PAFAbstractType.h"

/**
 * @class PAFArrayPrimitiveType
 * @brief Internal PAF class to holds ROOT arrays types (Float_t, Double_t...) TLeafs.
 */
template <class T>
class PAFArrayPrimitiveType : public PAFAbstractType
{
	public:
		/**
		 * Default constructor.
		 */
		PAFArrayPrimitiveType();

		/**
		 * Create PAFElementType using a TLeaf object.
		 *
		 * @param leaf TLeaf object.
		 */
		PAFArrayPrimitiveType(TLeaf* leaf);

		/**
		 * Destructor.
		 */
		virtual ~PAFArrayPrimitiveType();

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
		 * Calculate the number of items that the array contains.
		 *
		 * @return The number of items that the array contains.
		 */
		virtual Int_t GetNData();

	protected:
		/**
		 * Pointer to the data.
		 */
		void* fPointer;

	ClassDef(PAFArrayPrimitiveType<T>, 1);
};

template <class T>
PAFArrayPrimitiveType<T>::PAFArrayPrimitiveType()
	: PAFAbstractType(), fPointer(NULL)
{

}

template <class T>
PAFArrayPrimitiveType<T>::PAFArrayPrimitiveType(TLeaf* leaf)
	: PAFAbstractType(leaf)
{

}

template <class T>
PAFArrayPrimitiveType<T>::~PAFArrayPrimitiveType()
{

}

template <class T>
void* PAFArrayPrimitiveType<T>::GetPointer()
{
	EnableBranch();
	fPointer = fLeaf->GetValuePointer();
	return &fPointer;
}

template <class T>
void* PAFArrayPrimitiveType<T>::GetPointer(Int_t pos)
{
	EnableBranch();
	T* values = (T*)fLeaf->GetValuePointer();
	return &values[pos];
}

template <class T>
Int_t PAFArrayPrimitiveType<T>::GetNData()
{
	EnableBranch();
	return fLeaf->GetNdata();
}
