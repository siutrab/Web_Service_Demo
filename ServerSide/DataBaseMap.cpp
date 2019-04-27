#include "DataBaseMap.h"
#include "ExceptionsSystem.h"

typedef pair<string, TableInterface*> TablePair;
typedef vector<TablePair> TableList;

DataBaseMap::DataBaseMap()
	:	tableList(
		{
			shared_ptr<TableInterface>(new MaterialTable())

		})
{	
}


DataBaseMap::~DataBaseMap()
{
}

shared_ptr<TableInterface> DataBaseMap::findTable(string &tableName)
{
	for (size_t i = 0; i < tableList.size(); i++)
	{
		if (tableList[i]->getTableName() == tableName) return tableList[i];
	}

	throw ServerExceptions::QueryMappingExceptions::WrongTableName();
}

//bool DataBaseMap::thereIsTable(string& tableName)
//{
//	for (size_t i = 0; i < tableList->size(); i++)
//	{
//		shared_ptr<TableInterface> table = ((*tableList)[i]).second;
//		string& nameOfTable = ((*tableList)[i]).first;
//
//		if (tableName == nameOfTable)
//		{
//			foundTable = table;
//			return true;
//		}
//		foundTable = nullptr;
//		return false;
//	}
//}

//
//void DataBaseMap::assignTableMap(DocumentXml& document)
//{
//	if (thereIsTable(*document.getTableName()))
//		document.setTableMap(*foundTable);
//}

