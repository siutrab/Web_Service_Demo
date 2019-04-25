#pragma once
#include "QueueTemplate.h"
#include "Query.h"

class Query;

class ResultQueryQueue
	: public Queue<Query>
{
public:
	ResultQueryQueue();
	~ResultQueryQueue();
};
