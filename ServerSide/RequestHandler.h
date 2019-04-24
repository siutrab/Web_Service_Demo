#pragma once
#include <string.h>
#include <thread>
#include "pugixml.hpp"

#include "Request.h"
#include "RequestsQueue.h"
#include "MaterialEntity.h"
#include "DataBaseMap.h"
#include "DocumentXml.h"


using std::string;
using std::thread;
using pugi::xml_document;


class RequestsQueue;
class DataBaseMap;
class DocumentXml;
	//struct LoadedXmlDocument
	//{
	//	bool loadedSuccesfully;
	//	xml_document document;
	//};


	class RequestHandler
	{
		thread REQUEST_HANDLER_THREAD;
		bool running;
			static RequestsQueue* requestsQueue;
			//unique_ptr<LoadedXmlDocument> loadXmlDocument();
			
			unique_ptr<DataBaseMap> dataBaseMap;	// Owner
			DocumentXml* document;
	public:
		RequestHandler();
		~RequestHandler();

		void start();
		void stop();

		static void setRequestQueuePointer(RequestsQueue* pointer);
		void translateRequest();
		void translateResponse();

		
	};

