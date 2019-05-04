#include "DocumentXml.h"


DocumentXml::DocumentXml(Request& request)
	:	valid(false)
{
	string* requestContent = static_cast<string*>(request.getContent());
	eraseWhiteSigns(*requestContent);

	pugi::xml_parse_result result = document.load_string(requestContent->c_str());
	if (result)
		valid = true;
	std::cout << result.description() << std::endl;
}


DocumentXml::~DocumentXml()
{	}

void DocumentXml::eraseWhiteSigns(string& str)
{
	string textCopy = str;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] != '\t' && str[i] != '\n')
			textCopy += str[i];
	}
	str = textCopy;
}

string DocumentXml::findTableName()
{
	nodeXml tableNode = document.child("soap:Envelope").child("soap:Body").child("table");

	if (!tableNode)
	{
		recognizeInvalid();
		throw ServerExceptions::QueryMappingExceptions::NodeNotFound();
	}

	pugi::xml_attribute tableName = tableNode.attribute("name");
	const pugi::char_t* value = tableName.value();

	return string(value);
}

string DocumentXml::findMethodName()
{
	methodNode = document.child("soap:Envelope").child("soap:Body").child("table");
	
	if (!methodNode)
	{
		recognizeInvalid();
		throw ServerExceptions::QueryMappingExceptions::NodeNotFound();
	}
	
	pugi::xml_attribute methodName = methodNode.attribute("name");
	const pugi::char_t* value = methodName.value();
	
	return string(value);
}

unique_ptr<string> DocumentXml::getParameter(string& parameterName)
{
	const pugi::char_t* value = methodNode.child(parameterName.c_str()).child_value();
	auto valueString = std::make_unique<string>(new string(value));
	delete value;
	return std::move(valueString);
}

unique_ptr<vector<string>> DocumentXml::getParametersArray(string& collectionName, string& parameterName)		// WARNING!!! throws exception of type: boost::bad_lexical_cast
{
	auto valuesVector = std::make_unique<vector<string>>(new vector<string>());
	nodeXml collectionNode = methodNode.child(collectionName.c_str());
	nodeXml parameterNode = collectionNode.first_child();

	for (nodeXml i = parameterNode; i; parameterNode = i.next_sibling())
	{
		string stringValue(i.child_value());
		valuesVector->push_back(stringValue);
	}
	return std::move(valuesVector);
};


void DocumentXml::recognizeInvalid() { valid = false; }

bool DocumentXml::isValid() { return valid; }
