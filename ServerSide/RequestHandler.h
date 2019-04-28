#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

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


class RequestQueue;
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
			static RequestQueue* requestsQueue;
			//unique_ptr<LoadedXmlDocument> loadXmlDocument();
			
			unique_ptr<DataBaseMap> dataBaseMap;	// Owner
			DocumentXml* document;

		void run();
	public:
		RequestHandler();
		~RequestHandler();

		void start();
		void stop();

		static void setRequestQueuePointer(RequestQueue* pointer);
		void translateRequest();
		void translateResponse();

		
	};

#endif // !REQUEST_HANDLER_H
