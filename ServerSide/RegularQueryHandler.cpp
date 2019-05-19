#include "DatabaseHandler.h"
#include "RegularQueryHandler.h"


RegularQueryHandler::RegularQueryHandler(Queue* queryQueue, Queue* responseQueue, ErrorQueue* errorQueue, DatabaseHandler* databaseHandler)
	:	queryQueuePtr(queryQueue),
		responseQueuePtr(responseQueue),
		errorQueuePtr(errorQueue),
		databaseHandlerPtr(databaseHandler)
{
}


RegularQueryHandler::~RegularQueryHandler()
{
}

void  RegularQueryHandler::handleQuery()
{
	if (takeQueueItem())
	{
		SQLString sqlString = *static_cast<SQLString*>(queryContent->getContent());
	
		if (executeQuery(sqlString))
		{
			unique_ptr<ContentInterface> response = responseTranslator.generateSuccessMessage(*queueItem);
			queueItem->changeContent(response);
			responseQueuePtr->addItem(std::move(queueItem));

		}
		else
		{
			ServerExceptions::DatabaseExceptions::CannotExecuteQuery exception;
			errorQueuePtr->addItem(std::move(queueItem), exception);
		}
	}
	
}


bool RegularQueryHandler::takeQueueItem()
{
	if (queryQueuePtr->isEmpty())
	{
		return false;
	}
	else
	{
		queueItem.reset(queryQueuePtr->getItem().release());
		unique_ptr<ContentInterface> content(queueItem->getContentObject());
		queryContent.reset(static_cast<Query*>(content.release()));
		return true;
	}
}


bool RegularQueryHandler::executeQuery(SQLString& query)	
{
	try
	{
		SqlPreparedStatement.reset(sqlConnection->prepareStatement(query));

		return !SqlPreparedStatement->execute();	// this strange function returns false when succeed
	}
	catch (SQLException&)
	{
		return false;
	}
}

void RegularQueryHandler::setConnection(Connection* connection)
{
	sqlConnection = connection;
}