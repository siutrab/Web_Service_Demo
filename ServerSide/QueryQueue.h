#pragma once
#include "Queue.h"
#include "Query.h"
#include "TranslatorXml.h"
#include "DatabaseHandler.h"

class Query;

class QueryQueue
	: public Queue
{
public:
	QueryQueue();
	~QueryQueue();
};
