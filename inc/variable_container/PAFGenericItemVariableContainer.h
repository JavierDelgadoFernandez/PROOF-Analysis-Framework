/**
 * @brief Internal generic PAF class to store a variable of any type.
 * @file PAFGenericItemVariableContainer.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-01-26
 */

#pragma once

#include "TObject.h"

#include <iostream>

/**
 * @class PAFGenericItemVariableContainer
 * @brief Internal generic PAF class to store a variable of any type.
 */
template <class T>
class PAFGenericItemVariableContainer : public TObject
{
	public:
		/**
		 * Default constructor.
		 */
		PAFGenericItemVariableContainer() : TObject() {}

		/**
		 * Constructor with the value already initialized.
		 *
		 * @param object Value to be held.
		 */
		PAFGenericItemVariableContainer(T object) : TObject(), fObject(object) {}

		/**
		 * Destructor.
		 */
		virtual ~PAFGenericItemVariableContainer() {}

		/**
		 * Set the value of th object.
		 *
		 * @param object Value to be held.
		 *
		 */
		void Set(T object) { fObject = object; }

		/**
		 * Get the value of the object
		 *
		 * @return Value stored in this object.
		 */
		T Get() { return fObject; }

		//TODO Maybe an "IsType" function could facilitate the evolution.
	private:
		/**
		 * Value held.
		 */
		T fObject;

	ClassDef(PAFGenericItemVariableContainer<T>, 1);
};
