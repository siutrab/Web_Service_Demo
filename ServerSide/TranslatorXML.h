#pragma once
#include "pugixml.hpp"
#include "RequestResponseObject.h"
#include "RequestsQueue.h"

class RequestsQueue;

class TranslatorXML
{
	RequestsQueue* requestsQueue;
public:
	TranslatorXML(RequestsQueue* pointer);
	~TranslatorXML();
	void translateRequest();
	void translateResponse();
};

