#pragma once
#include <queue>
#include "jdbc/cppconn/sqlstring.h"
#include "Queue.h"
#include "Query.h"
#include <memory>
#include "DatabaseHandler.h"

using std::queue;
using sql::SQLString;
using std::unique_ptr;

class Request;

class NonResultQueryQueue
	: public Queue
{
public:
	NonResultQueryQueue();
	~NonResultQueryQueue();
};

