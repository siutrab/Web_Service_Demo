#include "ErrorTranslatorXml.h"



ErrorTranslatorXml::ErrorTranslatorXml()
{
}


ErrorTranslatorXml::~ErrorTranslatorXml()
{
}


void ErrorTranslatorXml::generateDocument(ExceptionInterface& exception, unsigned int requestId)
{
	resetDocument();
	
	auto responseNode = documentXml->append_child("response");
	auto idAttribute = responseNode.append_attribute("id");
	idAttribute.set_value(std::to_string(requestId).c_str());
	
	auto resultAttribute = responseNode.append_attribute("result");
	resultAttribute.set_value("fail");

	auto errorMessageNode = responseNode.append_child("error message");
	errorMessageNode.text.set_value(exception.getValue().c_str());
}

void ErrorTranslatorXml::resetDocument()
{
	documentXml.reset(new xml_document());
}