#pragma once
#include "pugixml.hpp"
#include "Request.h"
#include "RequestsQueueXML.h"
#include <string.h>
#include "DatabaseHandler.h"

using std::string;
using pugi::xml_document;


class DatabaseHandler;
class RequestsQueueXml;

	struct LoadedDocument
	{
		bool loadedSuccesfully;
		xml_document document;
	};

	class TranslatorXML
	{
			static RequestsQueueXml* requestsQueue;
			LoadedDocument* loadDocument();
			
	public:
		TranslatorXML();
		~TranslatorXML();
		void translateRequest();
		void translateResponse();
		static void setRequestQueuePointer(RequestsQueueXml* pointer);
	};

