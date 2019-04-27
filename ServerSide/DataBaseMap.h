#pragma once
#include <list>
#include "DocumentXml.h"
#include "TableInterface.h"
#include "MaterialTable.h"
#include "ExceptionsSystem.h"

using std::list;
using std::pair;
using std::unique_ptr;
using std::shared_ptr;

class DocumentXml;
class TableInterface;
class MaterialTable;

class DataBaseMap
{
	vector<shared_ptr<TableInterface>> tableList;


public:
	shared_ptr<TableInterface> findTable(string &tableName);

	void assignTableMap(DocumentXml& document);
	DataBaseMap();
	~DataBaseMap();
};
