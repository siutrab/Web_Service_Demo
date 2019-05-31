#pragma once
#include "MaterialTable.h"
#include "ExceptionsSystem.h"
#include <list>
#include <memory>
#include <vector>

using std::unique_ptr;
using std::vector;

class DocumentXml;
class TableInterface;
class MaterialTable;

class DataBaseMap
{
	vector<unique_ptr<TableInterface>> tableList;


public:
	TableInterface& findTable(string &tableName);	// returns table if found one, else throws an exception

	DataBaseMap();
	~DataBaseMap();
};
