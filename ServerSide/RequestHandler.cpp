//#include "pch.h"
//#include "ExceptionsSystem.h"
//#include "RequestHandler.h"
//
//RequestQueue* RequestHandler::requestsQueue;
//void RequestHandler::setRequestQueuePointer(RequestQueue* pointer)
//{
//	requestsQueue = pointer;
//	const_cast<RequestQueue* const>(requestsQueue);
//}
//
//RequestHandler::RequestHandler()
//	:	dataBaseMap(new DataBaseMap()),
//		running(false)
//{	
//
//}
//
//
//RequestHandler::~RequestHandler()
//{
//}
//
//void RequestHandler::translateRequest()
//{
//	
//}
//
//
//
//void RequestHandler::translateResponse()
//{
//
//}
//
//void RequestHandler::start()
//{
//	REQUEST_HANDLER_THREAD = thread(&RequestHandler::run, this);
//}
//
//void RequestHandler::run()
//{
//	running = true;
//	while (running)
//	{
//		
//	}
//}
//
//void RequestHandler::stop()
//{
//	running = false;
//	REQUEST_HANDLER_THREAD.join();
//}
