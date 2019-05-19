#include "TranslatorXml.h"



TranslatorXml::TranslatorXml(Queue* queryQueue, Queue* resultingQueryQueue, Queue* requestQueue, ErrorQueue* errorQueue)
	:	translatorFromXml(queryQueue, resultingQueryQueue, requestQueue, errorQueue)
{
}


TranslatorXml::~TranslatorXml()
{
}

void TranslatorXml::start()
{
	translatorFromXml.start();
}

void TranslatorXml::stop()
{
	translatorFromXml.stop();
}