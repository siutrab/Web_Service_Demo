#pragma once
#include "pugixml.hpp"
#include "TranslatorXML.h"
#include "Server.h"

class Server;
class TranslatorXML;

class RequestHandler
{
	bool running = false;
	TranslatorXML* translator;
	Server* const server;
public:
	RequestHandler(Server* const server);
	~RequestHandler();
	void start();
	void stop();
};

