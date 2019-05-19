#pragma once
#include "Queue.h"
#include "ErrorQueue.h"
#include "TranslatorFromXml.h"
#include "TranslatorToXml.h"

class TranslatorXml
{
	TranslatorFromXml translatorFromXml;
	TranslatorToXml translatorToXml;
public:
	TranslatorXml(Queue* queryQueue, Queue* resultingQueryQueue, Queue* requestQueue, Queue* responseQueue, Queue* entityQueue, ErrorQueue* errorQueue);
	~TranslatorXml();
	void start();
	void stop();
};

