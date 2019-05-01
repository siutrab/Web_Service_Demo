#pragma once
#include "ErrorResponse.h"
#include "Queue.h"
#include "Client.h"
//#include <queue>
//#include "jdbc/cppconn/sqlstring.h"
//#include "Queue.h"
//#include "Query.h"
//#include <memory>
//#include "DatabaseHandler.h"

//using std::queue;
//using sql::SQLString;
//using std::unique_ptr;

class Client;
class Request;

class ErrorQueue
	: public Queue
{
public:
	ErrorQueue();
	~ErrorQueue();
};

