#ifndef RESULT_QUERY_QUEUE_H
#define RESULT_QUERY_QUEUE_H


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

#endif // !RESULT_QUERY_QUEUE_H