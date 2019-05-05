#pragma once
#include <list>
#include <memory>
#include <vector>
#include "MaterialTable.h"
#include "ExceptionsSystem.h"

using std::unique_ptr;
using std::vector;

class DocumentXml;
class TableInterface;
class MaterialTable;

class DataBaseMap
{
	vector<unique_ptr<TableInterface>> tableList;


public:
	TableInterface& findTable(string &tableName);

	DataBaseMap();
	~DataBaseMap();
};
