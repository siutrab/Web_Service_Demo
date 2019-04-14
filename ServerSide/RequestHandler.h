#pragma once
#include "pugixml.hpp"
#include "RequestTranslatorXML.h"
#include "Server.h"

class Server;
class RequestTranslatorXML;

class RequestHandler
{
	bool running = false;
	RequestTranslatorXML* const translator;
	Server* const server;
public:
	RequestHandler(Server* const server);
	~RequestHandler();
	void start();
	void stop();
};

