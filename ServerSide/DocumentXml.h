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
using pugi::xml_attribute;

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


	void addEntitiesToDocument(vector<unique_ptr<EntityInterface>>& entitiesCollection, xml_node& parentNode);	// Appends entities to document
																												// that can be esily renslated do XML
public:
	DocumentXml(Request& request);	// Constructor of document from an XML file
	DocumentXml(vector<unique_ptr<EntityInterface>>& entitiesCollection, unsigned int responseIndex);	// Constructor from set of entities
	~DocumentXml();

	unique_ptr<string> generateXml();

	bool isDisconnectRequest();			// Checks if message is request for disconnection
	int getRequestID();					// Returns the id number of specific request. Throws exception!!!
	string findTableName();				// Returns the database table (that contains the methods lists). Throws exception!! 
	string findMethodName();			// Returns the method name. Throws exception!!!

	unique_ptr<string> getParameter(string& parameterName);	// Returns the parameter name
	unique_ptr<vector<string>> getParametersArray(string& collectionName, string& parameterName);

};
