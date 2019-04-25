#ifndef NON_RESULT_QUERY_QUEUE_H
#define NON_RESULT_QUERY_QUEUE_H


#pragma once
#include <queue>
#include "jdbc/cppconn/sqlstring.h"
#include "QueueTemplate.h"
#include "NonResultQuery.h"
#include <memory>
#include "DatabaseHandler.h"

using std::queue;
using sql::SQLString;
using std::unique_ptr;

class Request;

class NonResultQueryQueue
	: public Queue<NonResultQuery>
{
public:
	NonResultQueryQueue();
	~NonResultQueryQueue();
};

#endif // !NON_RESULT_QUERY_QUEUE_H
