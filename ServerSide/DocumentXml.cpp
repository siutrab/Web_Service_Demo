#include "DocumentXml.h"


DocumentXml::DocumentXml(Request& request)
	:	valid(false)
{
	string* requestContent = static_cast<string*>(request.getContent());
	eraseWhiteSigns(*requestContent);
	//const char* charPtr = textContent.c_str();
	pugi::xml_parse_result result = document.load_string(textContent.c_str());
	if (result)
		valid = true;
	std::cout << result.description() << std::endl;
}


DocumentXml::~DocumentXml()
{	}

void DocumentXml::eraseWhiteSigns(string& str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		//const char* charPtr = const_cast<const char*>(&str[i]);
		if (str[i] != '\t' && str[i] != '\n')
			textContent += str[i];
	}
}


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


unique_ptr<string> DocumentXml::getNodeAttriute(vector<string>& nodeHierarchyVector, string& attribute)
{
	size_t nodesNumber = nodeHierarchyVector.size();
	pugi::xml_node node = document;

	for (size_t i = 0; i < nodesNumber; i++)
		node = node.child(nodeHierarchyVector[i].c_str());
	
	//pugi::xml_node node = document.child("soap:Envelope").child("soap:Body").child(nodeName.c_str());
	pugi::xml_attribute nodeAttribute = node.attribute(attribute.c_str());
	const pugi::char_t* value = nodeAttribute.value();

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