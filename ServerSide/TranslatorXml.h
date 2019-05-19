#pragma once
#include "Queue.h"
#include "ErrorQueue.h"
#include "TranslatorFromXml.h"
#include "TranslatorToXml.h"

class TranslatorXml
{
	TranslatorFromXml translatorFromXml;
public:
	TranslatorXml(Queue* queryQueue, Queue* resultingQueryQueue, Queue* requestQueue, ErrorQueue* errorQueue);
	~TranslatorXml();
	void start();
	void stop();
};

