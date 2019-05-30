#pragma once
#include "Queue.h"
#include "Query.h"
#include "DatabaseHandler.h"
#include "ResponseTranslator.h"
#include "ErrorHandler.h"
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

class ErrorHandler;
class Queue;
class DatabaseHandler;

class RegularQueryHandler
{
		unique_ptr<QueueItem> queueItem;
		unique_ptr<Query> queryContent;

		Queue* queryQueuePtr;
		Queue* responseQueuePtr;
		ErrorHandler* errorQueuePtr;

		DatabaseHandler* databaseHandlerPtr;
		ResponseTranslator responseTranslator;
		Connection* sqlConnection;

		unique_ptr<PreparedStatement> SqlPreparedStatement;

	bool executeQuery(SQLString& query);
	bool takeQueueItem();	// initializes queueItem and queryContent fields
public:
	RegularQueryHandler(Queue* queryQueue, Queue* responseQueue, ErrorHandler* errorQueue, DatabaseHandler* databaseHandler);
	~RegularQueryHandler();
	void setConnection(Connection* connection);	// sets datbse connection
	void handleQuery();							// coordinates the query execution
};

