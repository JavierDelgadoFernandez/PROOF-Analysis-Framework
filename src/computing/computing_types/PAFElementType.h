/**
	@brief Internal PAF class to holds TLeafElements type.
	@file PAFElementType.h
	@class PAFElementType
	@author I. Gonzalez Caballero, J. Delgado Fernandez
	@version 1.0
	@date 2014-06-17
*/

#pragma once

#include "PAFAbstractType.h"

class PAFElementType : public PAFAbstractType
{
	public:
		PAFElementType();
		PAFElementType(TLeaf* leaf);
		virtual ~PAFElementType();

		virtual void* GetPointer(int pos);
	
		virtual int GetNData();

	ClassDef(PAFElementType, 1);
};
