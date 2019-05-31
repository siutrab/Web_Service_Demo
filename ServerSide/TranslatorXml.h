#pragma once
#include "Queue.h"
#include "ErrorHandler.h"
#include "RequestTranslatorXml.h"
#include "ResponseTranslatorXml.h"
#include "DataBaseMap.h"

class TranslatorXml
{
	DataBaseMap databaseMap;
	RequestTranslatorXml requestTranslator;
	ResponseTranslatorXml responseTranslator;
public:
	TranslatorXml(Queue* queryQueue, Queue* resultingQueryQueue, Queue* requestQueue, Queue* responseQueue, Queue* entityQueue, ErrorHandler* errorQueue);
	~TranslatorXml();
	void start();		// Creates two threads of request and response translation
	void stop();		// Stops threads
};

