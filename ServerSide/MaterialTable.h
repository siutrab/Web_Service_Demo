#pragma once
#include "MaterialEntity.h"
#include "TableInterface.h"
#include "CreateMethod.h"
#include "MethodsCollection.h"
#include <vector>

using std::unique_ptr;
using std::string;
using std::pair;

class TableInterface;

class MaterialTable
	:	public TableInterface
{
	MethodsCollection methodsMapper;
public:
	
	MaterialTable();
	~MaterialTable();
	string getTableName() override;
	MethodsCollection* getMethodsMapper() override;
};

