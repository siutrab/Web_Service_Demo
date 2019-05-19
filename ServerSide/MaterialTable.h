#pragma once
#include "MaterialEntity.h"
#include "TableInterface.h"
#include "CreateMethod.h"
#include "MethodsMapper.h"
#include <vector>

using std::unique_ptr;
using std::string;
using std::pair;

class TableInterface;

class MaterialTable
	:	public TableInterface
{
	MethodsMapper methodsMapper;
public:
	
	MaterialTable();
	~MaterialTable();
	string getTableName() override;
	MethodsMapper* getMethodsMapper() override;
};

