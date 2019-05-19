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


MethodsMapper* MaterialTable::getMethodsMapper()
{
	return &methodsMapper;
}