#include "MaterialTable.h"


MaterialTable::MaterialTable()
	: methodsMapper()
{	}

MaterialTable::~MaterialTable()
{	}

string MaterialTable::getTableName() 
{ 
	return "materials"; 
}


MethodsCollection* MaterialTable::getMethodsMapper()
{
	return &methodsMapper;
}