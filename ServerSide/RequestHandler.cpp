#include "pch.h"
#include "RequestHandler.h"


RequestHandler::RequestHandler()
	:	translator(&TranslatorXML())
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
