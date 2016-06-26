/**
 * @brief Container class which allows us a dynamic name assignment to any TObject.
 * @file PAFNamedItem.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-01-22
 */

#pragma once

#include "TNamed.h"

/**
 * @class PAFNamedItem
 * @brief Container class which allows us a dynamic name assignment to any TObject.
 */
class PAFNamedItem : public TNamed 
{
	public:
		/**
		 * Default constructor.
		 */
		PAFNamedItem();

		/**
		 * Constructor using the name and the object to be stored.
		 *
		 * @param name Name used to the object.
		 * @param object Object that it will be stored under the given name.
		 */
		PAFNamedItem(const char* name, TObject* object);


		/**
		 * Set the object.
		 *
		 * @param object Object to be stored.
		 */
		void SetObject(TObject* object);

		/**
		 * Return the object stored.
		 *
		 * @return Object stored.
		 */
		TObject* GetObject();

	protected:
		/**
		 * Named item.
		 */
		TObject* fObject;

	ClassDef(PAFNamedItem, 1);
};
