#pragma once
#include <string>
#include "pugixml.hpp"
#include <memory>

#include "Request.h"
#include "TableInterface.h"

#include "boost/lexical_cast.hpp"
#include "boost/lexical_cast/bad_lexical_cast.hpp"

using std::string;
using std::shared_ptr;
using std::unique_ptr;
using pugi::xml_document;
using std::vector;

class Request;

class DocumentXml
{
private:
		bool valid;
		xml_document document;
		string textContent;
		shared_ptr<TableInterface> tableMap;
		vector<ExceptionInterface> ExceptionsList;

	void setTableMap(TableInterface& table);
	void eraseWhiteSigns(string& str);
public:
	DocumentXml(Request& request);
	~DocumentXml();
	bool isValid();
	void recognizeInvalid();
	
	shared_ptr<TableInterface> getTableMap();
	unique_ptr<string> getNodeValue(string& nodeName);
	unique_ptr<string> getNodeValue(string& nodeName, string& parentNodeName);
	unique_ptr<string> getNodeAttriute(vector<string>& nodeHierarchyVector, string& attribute);

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
