#include "pch.h"
#include "RequestHandler.h"


RequestHandler::RequestHandler(Server* server)
	:	server(server),
		translator(new TranslatorXML(server->getRequestsQueuePtr()))
{

	start();
}

RequestHandler::~RequestHandler()
{
}

void RequestHandler::start()
{
	running = true;
	while (running)
	{
		translator->translateRequest();
		translator->translateResponse();
	}
}

void RequestHandler::stop()
{

}
