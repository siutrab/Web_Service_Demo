#include "pch.h"
#include "RequestHandler.h"


RequestHandler::RequestHandler(Server* const server)
	:	server(server),
		translator(new TranslatorXML(server->getRequestsQueuePtr()))
{	}

RequestHandler::~RequestHandler()
{	}

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
	running = false;
}
