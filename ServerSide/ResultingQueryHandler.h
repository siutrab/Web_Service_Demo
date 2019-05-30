#pragma once
#include "Query.h"
#include "Queue.h"
#include "ErrorHandler.h"
#include "MethodInterface.h"
#include "EntityInterface.h"
#include "ResultSetContent.h"
#include "Content.h"

#include "jdbc/cppconn/sqlstring.h"
#include "jdbc/mysql_error.h"
#include "jdbc/cppconn/exception.h"
#include "jdbc/mysql_connection.h"
#include "jdbc/cppconn/resultset.h"
#include "jdbc/cppconn/statement.h"

using sql::Statement;
using sql::ResultSet;

class Query;
class ResultingQuery;

class ResultingQueryHandler
{
		unique_ptr<QueueItem> queueItem;
		unique_ptr<ContentInterface> queryContent;
		ReadMethodInterface* method;

		Queue* resultingQueryQueuePtr;
		Queue* entityQueuePtr;
		ErrorHandler* errorHandlerPtr;

		ResponseTranslator responseTranslator;
		DatabaseHandler* databaseHandlerPtr;
		Connection* sqlConnection;
		unique_ptr<Statement> sqlStatement;
		shared_ptr<ResultSet> sqlResultSet;

	bool takeQueueItem();					// initilizing queueItem, queryContent and method
	void executeQuery(SQLString& query);	// executes query and set sqlResultSet

public:
	ResultingQueryHandler(Queue* resultingQueryQueue, Queue* entityQueue, ErrorHandler* errorQueue, DatabaseHandler* databaseHandler);
	~ResultingQueryHandler();
	void  handleQuery();						// Coordintes the query execution
	void setConnection(Connection* connection);	// Sets connection to database
};

