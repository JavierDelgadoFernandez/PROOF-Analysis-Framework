/**
 * @brief Internal PAF class to holds TLeafElements with pointers to std::vectors.
 * @file PAFElementVectorType.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-06-17
 */

#pragma once

#include "PAFElementType.h"
#include <vector>

/**
 * @class PAFElementVectorType
 * @brief Internal PAF class to holds TLeafElements with pointers to std::vectors.
 */
template <class T>
class PAFElementVectorType : public PAFElementType
{
	public:
		/**
		 * Default constructor.
		 */
		PAFElementVectorType();

		/**
		 * Create PAFElementType using a TLeaf object.
		 *
		 * @param leaf TLeaf object.
		 */
		PAFElementVectorType(TLeaf* leaf);

		/**
		 * Delete a PAFElementVectorType.
		 */
		virtual ~PAFElementVectorType();

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
		 * Calculate the number of items that the vector contains.
		 *
		 * @return Number of items that the vector contains.
		 */
		virtual Int_t GetNData();

	protected:
		/**
		 * Pointer to the value.
		 */
		T fValue;

	ClassDef(PAFElementVectorType<T>, 1);
};

template <class T>
PAFElementVectorType<T>::PAFElementVectorType()
	: PAFElementType()
{

}

template <class T>
PAFElementVectorType<T>::PAFElementVectorType(TLeaf* leaf)
	: PAFElementType(leaf)
{

}

template <class T>
PAFElementVectorType<T>::~PAFElementVectorType()
{

}

template <class T>
void* PAFElementVectorType<T>::GetPointer()
{
	EnableBranch();
	return fLeaf->GetValuePointer();
}

template <class T>
void* PAFElementVectorType<T>::GetPointer(Int_t pos)
{
	EnableBranch();
	std::vector<T>* values = (std::vector<T>*)fLeaf->GetValuePointer();
	fValue = values->at(pos);
	return &fValue;
}

template <class T>
Int_t PAFElementVectorType<T>::GetNData()
{
	EnableBranch();
	return (int)((std::vector<T>*)fLeaf->GetValuePointer())->size();
}
