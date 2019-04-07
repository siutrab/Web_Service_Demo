#pragma once
#include "pugixml.hpp"
#include "TranslatorXML.h"

class TranslatorXML;

class RequestHandler
{
	bool running = false;
	TranslatorXML* translator;
public:
	RequestHandler();
	~RequestHandler();
	void start();
	void stop();
};

