#include "pch.h"
#include "RequestHandler.h"

//
//RequestHandler::RequestHandler()
//	:	translator(new RequestHandler()),
//		//databaseHandler(unique_ptr<DatabaseHandler>(new DatabaseHandler()))
//{	
//	REQUEST_HANDLER_THREAD = thread(&RequestHandler::start, this);
//}
//
//RequestHandler::~RequestHandler()
//{	}
//
//void RequestHandler::start()
//{
//	running = true;
//	while (running)
//	{
//		translator->translateRequest();
//		translator->translateResponse();
//	}
//}
//
//void RequestHandler::stop()
//{
//	running = false;
//}
