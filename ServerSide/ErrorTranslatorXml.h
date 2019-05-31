#pragma once
#include "ExceptionsSystem.h"
#include "pugixml.hpp"
#include <memory>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;
using std::unique_ptr;
using pugi::xml_node;
using pugi::xml_attribute;
using pugi::xml_document;

class ExceptionInterfce;

class ErrorTranslatorXml
{
	unique_ptr<xml_document> documentXml;
	const string header = "<?xml version=\"1.0\"?>";

	void resetDocument();																		// Clearing the deocument
	void generateDocument(ExceptionInterface& exception, unsigned int requestId);				// sets the documentXml object
	unique_ptr<string> translateToXml();														// generates XML from documentXml
public:
	ErrorTranslatorXml();
	~ErrorTranslatorXml();

	unique_ptr<string> generateErrorXml(ExceptionInterface& exception, unsigned int requestId);	// returns pointer to XML file to send
};

