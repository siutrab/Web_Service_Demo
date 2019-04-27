#pragma once
#include <string>
#include "pugixml.hpp"

#include "Request.h"
#include "TableInterface.h"
#include "ExceptionsSystem.h"

using std::string;
using std::shared_ptr;
using pugi::xml_document;

class Request;

class DocumentXml
{
private:
		bool valid;
		xml_document document;
		shared_ptr<TableInterface> tableMap;
		vector<ExceptionInterface> ExceptionsList;

	void setTableMap(TableInterface& table);
public:
	DocumentXml(Request& request);
	~DocumentXml();
	bool isValid();
	void recognizeInvalid();
	unique_ptr<string> getTableName();

	shared_ptr<TableInterface> getTableMap();
	unique_ptr<string> getNodeValue(string& nodeName);
	unique_ptr<string> getNodeValue(string& nodeName, string& parentNodeName);
	unique_ptr<string> getNodeAttriute(string& nodeName, string& attribute);

	void addException(ExceptionInterface& exception);
};
