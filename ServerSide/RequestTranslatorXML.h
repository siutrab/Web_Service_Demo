#pragma once
#include "pugixml.hpp"
#include "Request.h"
#include "RequestsQueue.h"
#include <string.h>

using std::string;
using pugi::xml_document;

class RequestsQueue;

	struct LoadedDocument
	{
		bool loadedSuccesfully;
		xml_document document;
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

