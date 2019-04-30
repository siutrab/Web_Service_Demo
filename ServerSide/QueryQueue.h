#pragma once
#include "Queue.h"
#include "Query.h"
#include "TranslatorXml.h"

class Query;

class QueryQueue
	: public Queue
{
public:
	QueryQueue();
	~QueryQueue();
};
