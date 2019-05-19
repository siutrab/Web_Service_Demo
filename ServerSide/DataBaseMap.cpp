#include "TranslatorFromXml.h"
#include "DataBaseMap.h"


typedef pair<string, TableInterface*> TablePair;
typedef vector<TablePair> TableList;

DataBaseMap::DataBaseMap()
{	
	unique_ptr<TableInterface> materialTablePtr(new MaterialTable);
	tableList.push_back(std::move(materialTablePtr));
}


DataBaseMap::~DataBaseMap()
{	}

TableInterface& DataBaseMap::findTable(string &tableName)
{
	for (size_t i = 0; i < tableList.size(); i++)
	{
		if (tableList[i]->getTableName() == tableName) return *tableList[i];
	}

	throw ServerExceptions::QueryMappingExceptions::WrongTableName();
}
