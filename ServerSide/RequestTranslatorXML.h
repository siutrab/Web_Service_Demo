#pragma once
#include "pugixml.hpp"
#include "Request.h"
#include "RequestsQueue.h"
#include <string.h>

class RequestsQueue;
struct LoadedDocument
{
	bool loadedSuccesfully;
	pugi::xml_document document;
};

class RequestTranslatorXML
{
		RequestsQueue* requestsQueue;
		
	LoadedDocument* loadDocument();
public:
	RequestTranslatorXML(RequestsQueue* pointer);
	~RequestTranslatorXML();
	void translateRequest();
	void translateResponse();
};

