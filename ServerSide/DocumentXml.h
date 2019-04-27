#pragma once
#include <string>
#include "pugixml.hpp"

#include "Request.h"
#include "TableInterface.h"
#include "ExceptionsSystem.h"
#include "boost/lexical_cast.hpp"
#include "boost/lexical_cast/bad_lexical_cast.hpp"

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

	template<typename T>
	shared_ptr<vector<T>> getChildrenNodesValues(string& nodeName)		// WARNING!!! throws exception of type: boost::bad_lexical_cast
	{
		unique_ptr<vector<T>> valuesVector(new vector<T>());
		pugi::xml_node childNode = document.first_child();

		for (pugi::xml_node i = childNode; i; childNode = i.next_sibling())
		{

			string stringValue(i.value());
			T castedValue = boost::lexical_cast<T>(stringValue);
			valuesVector->push_back(castedValue);
		}

		return valuesVector;
	};	

	void addException(ExceptionInterface& exception);
};
