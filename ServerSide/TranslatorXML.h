#pragma once
#include "pugixml.hpp"
#include "Request.h"
#include "RequestsQueue.h"

class RequestsQueue;
struct LoadedDocument
{
	bool loadedSuccesfully;
	pugi::xml_document document;
};

class TranslatorXML
{
		RequestsQueue* requestsQueue;
		
	LoadedDocument* loadDocument();
public:
	TranslatorXML(RequestsQueue* pointer);
	~TranslatorXML();
	void translateRequest();
	void translateResponse();
};

