#include "DocumentXml.h"


DocumentXml::DocumentXml(Request& request)
	:	valid(false)
{
	string* requestContent = request.getContent();

	if (document.load_string(requestContent->c_str()))
		valid = true;
}


DocumentXml::~DocumentXml()
{	}


unique_ptr<string> DocumentXml::getNodeValue(string& nodeName)
{
	pugi::xml_node selectedNode = document.child(nodeName.c_str());

	// node not found
	if (!selectedNode)
	{
		recognizeInvalid();
		throw ServerExceptions::QueryMappingExceptions::NodeNotFound();
	}

	return unique_ptr<string>(new string(selectedNode.value()));
}


unique_ptr<string> DocumentXml::getNodeValue(string& nodeName, string& parentNodeName)
{
	pugi::xml_node parentNode = document.child(parentNodeName.c_str());
	pugi::xml_node childNode = parentNode.child(nodeName.c_str());

	// node not found
	if (!childNode)
	{
		recognizeInvalid();
		throw ServerExceptions::QueryMappingExceptions::NodeNotFound();
	}

	return unique_ptr<string>(new string(childNode.value()));
}


unique_ptr<string> DocumentXml::getNodeAttriute(string& nodeName, string& attribute)
{
	pugi::xml_node node = document.child(nodeName.c_str());
	pugi::xml_attribute nodeAttribute = node.attribute(attribute.c_str());
	const pugi::char_t* value = node.value();

	return unique_ptr<string>(new string(value));
}

void DocumentXml::recognizeInvalid() { valid = false; }

bool DocumentXml::isValid() { return valid; }

void DocumentXml::setTableMap(TableInterface& table) { *tableMap = table; }

shared_ptr<TableInterface> DocumentXml::getTableMap() { return tableMap; }

void DocumentXml::addException(ExceptionInterface& exception)
{
	recognizeInvalid();
	ExceptionsList.push_back(exception);
}