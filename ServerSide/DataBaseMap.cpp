#include "DataBaseMap.h"
#include "ExceptionsSystem.h"

typedef pair<string, TableInterface*> TablePair;
typedef vector<TablePair> TableList;


//TableInterface* DataBaseMap::findTable(string &tableName)
//{
//	for (int i = 0; i < tableList->size(); i++)
//	{
//		TableInterface* table = ((*tableList)[i]).second;
//		string& nameOfTable = ((*tableList)[i]).first;
//
//		if (tableName == nameOfTable) return table;
//	}
//	DatabaseExceptions::QueryException::WrongTableName e;
//	throw &e;
//}

bool DataBaseMap::thereIsTable(string& tableName)
{
	for (size_t i = 0; i < tableList->size(); i++)
	{
		shared_ptr<TableInterface> table = ((*tableList)[i]).second;
		string& nameOfTable = ((*tableList)[i]).first;

		if (tableName == nameOfTable)
		{
			foundTable = table;
			return true;
		}
		foundTable = nullptr;
		return false;
	}
}


void DataBaseMap::assignTableMap(DocumentXml& document)
{
	if (thereIsTable(*document.getTableName()))
		document.setTableMap(*foundTable);
}

DataBaseMap::DataBaseMap()
	:	tableList(new TableList())
{
	//TablePair materialTablePair("materials", shared_ptr<TableInterface>(new MaterialTable()));
	TablePair materialTablePair;
	materialTablePair.first = "materials";
	materialTablePair.second = shared_ptr<TableInterface>(new MaterialTable());
	tableList->push_back(materialTablePair);
}


DataBaseMap::~DataBaseMap()
{
}
