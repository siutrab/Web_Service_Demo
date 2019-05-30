#include "ErrorTranslatorXml.h"


ErrorTranslatorXml::ErrorTranslatorXml()
{	}


ErrorTranslatorXml::~ErrorTranslatorXml()
{	}

unique_ptr<string> ErrorTranslatorXml::generateErrorXml(ExceptionInterface& exception, unsigned int requestId)
{
	resetDocument();
	generateDocument(exception, requestId);
	auto resultString = translateToXml();
	return std::move(resultString);
}


void ErrorTranslatorXml::resetDocument()
{
	documentXml.reset(new xml_document());
}


void ErrorTranslatorXml::generateDocument(ExceptionInterface& exception, unsigned int requestId)
{	
	auto responseNode = documentXml->append_child("response");

	auto idAttribute = responseNode.append_attribute("id");
	idAttribute.set_value(std::to_string(requestId).c_str());
	
	auto resultAttribute = responseNode.append_attribute("result");
	resultAttribute.set_value("fail");

	auto errorMessageNode = responseNode.append_child("error message");
	errorMessageNode.text().set(exception.getValue().c_str());
}


unique_ptr<string> ErrorTranslatorXml::translateToXml()
{
	std::stringstream stringStream;
	auto resultString = std::make_unique<string>(header);

	documentXml->print(stringStream);
	*resultString += stringStream.str();

	return std::move(resultString);
}