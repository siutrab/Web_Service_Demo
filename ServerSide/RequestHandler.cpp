#include "pch.h"
#include "ExceptionsSystem.h"
#include "RequestHandler.h"

RequestsQueue* RequestHandler::requestsQueue;
void RequestHandler::setRequestQueuePointer(RequestsQueue* pointer)
{
	requestsQueue = pointer;
	const_cast<RequestsQueue* const>(requestsQueue);
}

RequestHandler::RequestHandler()
	:	dataBaseMap(new DataBaseMap()),
		running(false)
{	

}


RequestHandler::~RequestHandler()
{
}

void RequestHandler::translateRequest()
{
	
}



void RequestHandler::translateResponse()
{

}

void RequestHandler::start()
{
	REQUEST_HANDLER_THREAD = thread(&RequestHandler::run, this);
}

void RequestHandler::run()
{
	running = true;
	while (running)
	{
		
	}
}

void RequestHandler::stop()
{
	running = false;
	//std::thread::join();
}
