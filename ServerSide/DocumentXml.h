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
	typedef pugi::xml_node nodeXml;
	typedef pugi::xml_attribute attributeXml;
private:
		xml_document document;
		nodeXml methodNode;

	void eraseWhitespaces(string& str);

public:
	DocumentXml(Request& request);
	~DocumentXml();

	string findTableName();
	string findMethodName();

	unique_ptr<string> getParameter(string& parameterName);
	unique_ptr<vector<string>> getParametersArray(string& collectionName, string& parameterName);

};
