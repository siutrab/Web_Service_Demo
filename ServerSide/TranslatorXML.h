#pragma once
#include "pugixml.hpp"
#include "Request.h"
#include "RequestsQueue.h"
#include <string.h>
#include "DatabaseHandler.h"
#include "MaterialEntity.h"

using std::string;
using pugi::xml_document;


class DatabaseHandler;
class RequestsQueue;

	struct LoadedDocument
	{
		bool loadedSuccesfully;
		xml_document document;
	};


	class TranslatorXML
	{
			static RequestsQueue* requestsQueue;
			LoadedDocument* loadDocument();
			
	public:
		TranslatorXML();
		~TranslatorXML();
		void translateRequest();
		void translateResponse();
		static void setRequestQueuePointer(RequestsQueue* pointer);
	};

