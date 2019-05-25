#pragma once
#include "Queue.h"
#include "ErrorQueue.h"
#include "RequestTranslatorXml.h"
#include "ResponseTranslatorXml.h"
#include "DataBaseMap.h"

class TranslatorXml
{
	DataBaseMap databaseMap;
	RequestTranslatorXml requestTranslator;
	ResponseTranslatorXml responseTranslator;
public:
	TranslatorXml(Queue* queryQueue, Queue* resultingQueryQueue, Queue* requestQueue, Queue* responseQueue, Queue* entityQueue, ErrorQueue* errorQueue);
	~TranslatorXml();
	void start();
	void stop();
};

