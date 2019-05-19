#pragma once
#include "Query.h"
#include "Queue.h"
#include "ErrorQueue.h"
#include "MethodInterface.h"
#include "EntityInterface.h"
#include "EntityCollection.h"

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
		ErrorQueue* errorQueuePtr;

		ResponseTranslator responseTranslator;
		DatabaseHandler* databaseHandlerPtr;
		Connection* sqlConnection;
		unique_ptr<Statement> sqlStatement;
		unique_ptr<ResultSet> sqlResultSet;

	bool takeQueueItem();
	void executeQuery(SQLString& query);
	void generateEntities();
public:
	ResultingQueryHandler(Queue* resultingQueryQueue, Queue* entityQueue, ErrorQueue* errorQueue, DatabaseHandler* databaseHandler);
	~ResultingQueryHandler();
	void  handleQuery();
	void setConnection(Connection* connection);
};

