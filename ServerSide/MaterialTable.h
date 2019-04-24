#pragma once
#include <vector>
#include "MaterialEntity.h"
//#include "TableInterface.h"
#include "TableInterface.h"

using std::unique_ptr;
using std::string;
using std::pair;

class TableInterface;

class MaterialTable
	:	public TableInterface
{
	//typedef vector <pair<unique_ptr<string>, unique_ptr<string>>> valueVector;

public:
	//static unique_ptr<MaterialEntity> createEntity(valueVector &initialValues);
	static bool isNonResultMethod(string& methodName);
	MaterialTable();
	~MaterialTable();
};

