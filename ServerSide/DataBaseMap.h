#ifndef DATABASE_MAP_H
#define DATABASE_MAP_H


#pragma once
#include <list>
#include "DocumentXml.h"
#include "TableInterface.h"
//#include "MaterialTable.h"
#include "MaterialTable.h"

//#include "ExceptionsSystem.h"

using std::list;
using std::pair;
using std::unique_ptr;
using std::shared_ptr;

class DocumentXml;
class TableInterface;
//class MaterialTable;
class MaterialTable;

class DataBaseMap
{
	typedef pair<string, shared_ptr<TableInterface>> TablePair;
	typedef vector<TablePair> TableList;
	
	unique_ptr<TableList> tableList;

	shared_ptr<TableInterface> foundTable;


	bool thereIsTable(string& tableName);
public:
	// TableInterface* findTable(string &tableName);

	void assignTableMap(DocumentXml& document);
	DataBaseMap();
	~DataBaseMap();
};


#endif // !DATABASE_MAP_H