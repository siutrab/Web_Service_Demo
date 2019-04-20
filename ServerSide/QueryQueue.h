#pragma once
#include <queue>
#include "jdbc/cppconn/sqlstring.h"
#include "QueueTemplate.h"
#include <memory>

using std::queue;
using sql::SQLString;
using std::unique_ptr;

class Request;
class QueryQueue
	: public Queue<SQLString>
{


public:
	QueryQueue();
	~QueryQueue();


};

