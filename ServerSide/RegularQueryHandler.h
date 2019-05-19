#pragma once
#include "Queue.h"
#include "Query.h"
#include "DatabaseHandler.h"
#include "ResponseTranslator.h"
#include "ErrorQueue.h"
#include "ExceptionsSystem.h"

#include "jdbc/cppconn/sqlstring.h"
#include "jdbc/mysql_error.h"
#include "jdbc/cppconn/exception.h"
#include "jdbc/mysql_connection.h"
#include "jdbc/cppconn/prepared_statement.h"

#include <memory>


using sql::SQLString;
using sql::SQLException;
using sql::Connection;
using sql::PreparedStatement;
using std::unique_ptr;

class ErrorQueue;
class Queue;

class RegularQueryHandler
{
		unique_ptr<QueueItem> queueItem;
		unique_ptr<Query> queryContent;

		Queue* queryQueuePtr;
		Queue* responseQueuePtr;
		ErrorQueue* errorQueuePtr;

		DatabaseHandler* databaseHandlerPtr;
		ResponseTranslator responseTranslator;
		Connection* sqlConnection;

		unique_ptr<PreparedStatement> SqlPreparedStatement;

	bool executeQuery(SQLString& query);
	bool takeQueueItem();
public:
	RegularQueryHandler(Queue* queryQueue, Queue* responseQueue, ErrorQueue* errorQueue, DatabaseHandler* databaseHandler);
	~RegularQueryHandler();
	void setConnection(Connection* connection);
	void handleQuery();
};

