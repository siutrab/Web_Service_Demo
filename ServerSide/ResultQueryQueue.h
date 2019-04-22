#pragma once
#include "QueueTemplate.h"
#include "ResultQuery.h"


class ResultQuery;

class ResultQueryQueue
	: public Queue<ResultQuery>
{
public:
	ResultQueryQueue();
	~ResultQueryQueue();
};