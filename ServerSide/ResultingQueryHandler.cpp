#include "DatabaseHandler.h"
#include "ResultingQueryHandler.h"


ResultingQueryHandler::ResultingQueryHandler(Queue* resultingQueryQueue, Queue* responseQueue, ErrorHandler* errorQueue, DatabaseHandler* databaseHandler)
	:	resultingQueryQueuePtr(resultingQueryQueue),
		entityQueuePtr(responseQueue),
		errorHandlerPtr(errorQueue),
		databaseHandlerPtr(databaseHandler)
{	}

ResultingQueryHandler::~ResultingQueryHandler()
{	}

void  ResultingQueryHandler::handleQuery()
{
	if (takeQueueItem())
	{
		SQLString* query = static_cast<SQLString*>(queryContent->getContent());
		
		try
		{
			executeQuery(*query);

			unique_ptr<ContentInterface> newContent = std::make_unique<ResultSetContent>(sqlResultSet, method);
			queueItem->changeContent(newContent);
			entityQueuePtr->addItem(std::move(queueItem));
		}
		catch (ExceptionInterface& e)
		{
			errorHandlerPtr->createError(std::move(queueItem), e);
		}
	}
}


bool ResultingQueryHandler::takeQueueItem()
{
	if (resultingQueryQueuePtr->isEmpty())
	{
		return false;
	}
	else
	{
		queueItem.reset(resultingQueryQueuePtr->getItem().release());
		queryContent.reset(queueItem->getContentObject().release());
		

		auto resultingQuery = dynamic_cast<ResultingQuery*>(queryContent.get());

		method = resultingQuery->getMethodPointer();
		return true;
	}
}


void ResultingQueryHandler::executeQuery(SQLString& query)
{
	try
	{
		sqlStatement.reset(sqlConnection->createStatement());
		sqlResultSet.reset(sqlStatement->executeQuery(query));
	}
	catch(SQLException&)
	{
		throw ServerExceptions::DatabaseExceptions::CannotExecuteQuery();
	}
}


void ResultingQueryHandler::setConnection(Connection* connection)
{
	sqlConnection = connection;
}