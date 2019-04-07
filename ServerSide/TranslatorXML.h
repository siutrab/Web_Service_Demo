#pragma once
#include "pugixml.hpp"
#include "RequestResponseObject.h"
#include "RequestsQueue.h"

class RequestsQueue;

class TranslatorXML
{
	const RequestsQueue* requestsQueue;
public:
	TranslatorXML();
	~TranslatorXML();
	void translateRequest();
	void translateResponse();
};

