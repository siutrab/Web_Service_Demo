#include "TranslatorXml.h"



TranslatorXml::TranslatorXml(Queue* queryQueue, Queue* resultingQueryQueue, Queue* requestQueue, Queue* responseQueue, Queue* entityQueue, ErrorQueue* errorQueue)
	:	databaseMap(),
		requestTranslator(queryQueue, resultingQueryQueue, requestQueue, errorQueue, &databaseMap),
		responseTranslator(errorQueue, responseQueue, entityQueue)
{
}


TranslatorXml::~TranslatorXml()
{
}

void TranslatorXml::start()
{
	requestTranslator.start();
	responseTranslator.start();
}

void TranslatorXml::stop()
{
	requestTranslator.stop();
	responseTranslator.stop();
}