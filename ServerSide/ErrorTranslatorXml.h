#pragma once
#include "ExceptionsSystem.h"
#include "pugixml.hpp"
#include <memory>
#include <string>

using std::string;
using std::unique_ptr;
using pugi::xml_node;
using pugi::xml_attribute;
using pugi::xml_document;

class ExceptionInterfce;

class ErrorTranslatorXml
{
	unique_ptr<xml_document> documentXml;
	const string header = "<?xml version=\"1.0\"?>";

	void resetDocument();
	void generateDocument(ExceptionInterface& exception, unsigned int requestId);
public:
	ErrorTranslatorXml();
	~ErrorTranslatorXml();

	unique_ptr<string> generateErrorXml();
};

