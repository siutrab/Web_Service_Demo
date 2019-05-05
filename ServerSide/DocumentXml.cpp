#include "DocumentXml.h"


DocumentXml::DocumentXml(Request& request)
{
	string* requestContent = static_cast<string*>(request.getContent());
	eraseWhitespaces(*requestContent);

	pugi::xml_parse_result result = document.load_string(requestContent->c_str());
	if (!result)
		throw ServerExceptions::QueryMappingExceptions::InvalidDocument();
	
	std::cout << result.description() << std::endl;	/////////////////////////////////////////////////////////////////
}


DocumentXml::~DocumentXml()
{	}

void DocumentXml::eraseWhitespaces(string& str)
{
	string newStr;
	for (size_t i = 0; i < str.size(); i++)
	{
		char c = str[i];
		if (c != '\n' && c != '\r' && c != '\t' && c != '\v' && c != '\f')		// space ' ' cannot be deleted because tags could contain them
			newStr += c;														// for example <tag attribute = "...">
	}
	str = newStr;
}

string DocumentXml::findTableName()
{
	nodeXml tableNode = document.child("soap:Envelope").child("soap:Body").child("table");

	if (!tableNode)
		throw ServerExceptions::QueryMappingExceptions::NodeNotFound();

	attributeXml tableName = tableNode.attribute("name");
	const pugi::char_t* value = tableName.value();

	return string(value);
}

string DocumentXml::findMethodName()
{
	methodNode = document.child("soap:Envelope").child("soap:Body").child("method");
	
	if (!methodNode)
		throw ServerExceptions::QueryMappingExceptions::NodeNotFound();
	
	attributeXml methodName = methodNode.attribute("name");
	const pugi::char_t* value = methodName.value();
	
	return string(value);
}

unique_ptr<string> DocumentXml::getParameter(string& parameterName)
{
	const pugi::char_t* value = methodNode.child(parameterName.c_str()).child_value();
	auto valueString = std::make_unique<string>(value);
	//delete value;
	return std::move(valueString);
}

unique_ptr<vector<string>> DocumentXml::getParametersArray(string& collectionName, string& parameterName)		// WARNING!!! throws exception of type: boost::bad_lexical_cast
{
	auto valuesVector = std::make_unique<vector<string>>();
	nodeXml collectionNode = methodNode.child(collectionName.c_str());
	nodeXml parameterNode = collectionNode.first_child();

	for (auto i = collectionNode.begin(); i!= collectionNode.end(); i++)
	{
		string stringValue(i->child_value());
		valuesVector->push_back(stringValue);
	}
	return std::move(valuesVector);
};
