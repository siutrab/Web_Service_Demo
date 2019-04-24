#include "DocumentXml.h"



DocumentXml::DocumentXml(Request& request)
	:	loadedSuccesfully(false),
		tableAssigned(false)
{
	string& requestContent = request.getContent();

	if (document.load_string(requestContent.c_str()))
		loadedSuccesfully = true;
}


DocumentXml::~DocumentXml()
{	}


unique_ptr<string> DocumentXml::getTableName()
{
	pugi::xml_node tableNode = document.child("table");
	unique_ptr<string> tableName(new string());
	*tableName = tableNode.attribute("name").value();
	//string tableName = tableNode.attribute("name").value();
	return tableName;
}


bool DocumentXml::tableIsAssigned() { return tableAssigned; }

void DocumentXml::setTableMap(TableInterface& table) { *tableMap = table; }

shared_ptr<TableInterface> DocumentXml::getTableMap() { return tableMap; }

bool DocumentXml::isLoadedSuccesfully() { return loadedSuccesfully; }