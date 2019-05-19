#include "DatabaseHandler.h"
#include "ResultingQueryHandler.h"


ResultingQueryHandler::ResultingQueryHandler(Queue* resultingQueryQueue, Queue* responseQueue, ErrorQueue* errorQueue, DatabaseHandler* databaseHandler)
	:	resultingQueryQueuePtr(resultingQueryQueue),
		entityQueuePtr(responseQueue),
		errorQueuePtr(errorQueue),
		databaseHandlerPtr(databaseHandler)
{
}

ResultingQueryHandler::~ResultingQueryHandler()
{
}

void  ResultingQueryHandler::handleQuery()
{
	if (takeQueueItem())
	{
		SQLString* query = static_cast<SQLString*>(queryContent->getContent());
		
		try
		{
			executeQuery(*query);

			/*ResultingQuery* resultingQuery = dynamic_cast<ResultingQuery*>(queryContent.get());
			auto method = resultingQuery->getMethodPointer();*/

			/*auto entityVector = method->generateEntities(*sqlResultSet);
			unique_ptr<ContentInterface> content = std::make_unique<EntityCollection>(entityVector);
			queueItem->changeContent(content);*/

			generateEntities();
			entityQueuePtr->addItem(std::move(queueItem));
		}
		catch (ExceptionInterface& e)
		{
			errorQueuePtr->addItem(std::move(queueItem), e);
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

void ResultingQueryHandler::generateEntities()
{
	auto entityVector = method->generateEntities(*sqlResultSet);
	unique_ptr<ContentInterface> content = std::make_unique<EntityCollection>(entityVector);
	queueItem->changeContent(content);
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