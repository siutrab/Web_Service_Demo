#pragma once
#include <string>
#include "Request.h"
#ifndef DOCUMENT_XML_H
#define DOCUMENT_XML_H


#include "pugixml.hpp"
#include "TableInterface.h"

using std::string;
using std::shared_ptr;
using pugi::xml_document;

class Request;

class DocumentXml
{
private:
		bool loadedSuccesfully;
		bool tableAssigned;
		xml_document document;
		shared_ptr<TableInterface> tableMap;
public:
	DocumentXml(Request& request);
	~DocumentXml();
	bool isLoadedSuccesfully();
	bool tableIsAssigned();
	unique_ptr<string> getTableName();

	shared_ptr<TableInterface> getTableMap();
	void setTableMap(TableInterface& table);

};


#endif // !DOCUMENT_XML_H