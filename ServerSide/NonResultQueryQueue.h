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
class ResultQuery;

class NonResultQueryQueue
	: public Queue<ResultQuery>
{
public:
	NonResultQueryQueue();
	~NonResultQueryQueue();
};

