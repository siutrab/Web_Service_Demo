#include "TranslatorXml.h"



TranslatorXml::TranslatorXml(Queue* queryQueue, Queue* resultingQueryQueue, Queue* requestQueue, Queue* responseQueue, Queue* entityQueue, ErrorQueue* errorQueue)
	:	translatorFromXml(queryQueue, resultingQueryQueue, requestQueue, errorQueue),
		translatorToXml(errorQueue, responseQueue, entityQueue)
{
}


TranslatorXml::~TranslatorXml()
{
}

void TranslatorXml::start()
{
	translatorFromXml.start();
	translatorToXml.start();
}

void TranslatorXml::stop()
{
	translatorFromXml.stop();
	translatorFromXml.stop();
}