/**
 * @brief Internal PAF class to store variables of any type.
 * @file PAFVariableContainer.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-01-26
 */

#pragma once

#include "PAFGenericItemVariableContainer.h"

#include "TMap.h"
#include "TList.h"
#include "TObject.h"
#include "TObjString.h"
#include "TString.h"

#include "PAF.h"


/**
 * @class PAFVariableContainer
 * @brief Internal PAF class to store variables of any type.
 */
class PAFVariableContainer : public TObject
{
	public:
		/**
		 * Default constructor.
		 */
		PAFVariableContainer();

		/**
		 * Destructor.
		 */
		virtual ~PAFVariableContainer();

		/**
		 * Add a new key with the given value.
		 *
		 * @param key Key that will hold the value.
		 * @param value Value of the key.
		 * @tparam T Type of the value.
		 */
		template<typename T>
		void Add(const char* key, T value);

		/**
		 * Return the value of a key.
		 *
		 * @param key Key that contains the value.
		 * @tparam T Type of the value.
		 */
		template<typename T>
		T Get(const char* key);

		/**
		 * Return the list of keys that the container already has.
		 *
		 * @return List of keys.
		 */
		TList* GetKeys();

		/**
		 * Check if a given Key is already in the container.
		 *
		 * @param key Key to check.
		 */
		bool Exists(const char* key);

	protected:
		/**
		 * Dictionary with the pairs Key-Value.
		 */
		TMap fPairs;

	ClassDef(PAFVariableContainer, 1);
};

template <typename T>
inline void PAFVariableContainer::Add(const char* key, T value)
{
	TObjString* objKey = new TObjString(key);

	delete fPairs.Remove(objKey);

	fPairs.Add(objKey, new PAFGenericItemVariableContainer<T>(value));
}

template <typename T>
inline T PAFVariableContainer::Get(const char* key)
{
	TObjString tKey(key);
	PAFGenericItemVariableContainer<T>* result = (PAFGenericItemVariableContainer<T>*)fPairs.GetValue(&tKey);
	if (result)
	{
		return result->Get();
	}
	else
	{
		PAF_FATAL("PAFVariableContainer", TString::Format("Variable %s not found.", key).Data());
	}
}
