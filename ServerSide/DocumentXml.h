#pragma once
#include "Request.h"
#include "TableInterface.h"
#include "EntityInterface.h"

#include <string>
#include <sstream>
#include "pugixml.hpp"
#include <memory>

#include "boost/lexical_cast.hpp"
#include "boost/lexical_cast/bad_lexical_cast.hpp"

using std::string;
using std::vector;
using std::unique_ptr;
using pugi::xml_node;
using pugi::xml_document;

class Request;
extern void eraseSpaces(string& str);
extern void eraseWhitespacesExceptSpace(string& str);

class DocumentXml
{
	typedef pugi::xml_node nodeXml;
	typedef pugi::xml_attribute attributeXml;
private:
		xml_document document;
		nodeXml methodNode;



public:
	DocumentXml(Request& request);
	DocumentXml(vector<unique_ptr<EntityInterface>>& entitiesCollection);
	~DocumentXml();

	unique_ptr<string> generateXml();

	int getRequestID();
	string findTableName();
	string findMethodName();

	unique_ptr<string> getParameter(string& parameterName);
	unique_ptr<vector<string>> getParametersArray(string& collectionName, string& parameterName);

};
