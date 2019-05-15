#include "pch.h"
#include "DatabaseHandler.h"

// static members
const SQLString DatabaseHandler::DatabaseInfo::hostName = "localhost";
const SQLString DatabaseHandler::DatabaseInfo::userName = "user_for_materials";
const SQLString DatabaseHandler::DatabaseInfo::password = "haslo";
const SQLString DatabaseHandler::DatabaseInfo::schema = "building_materials";


DatabaseHandler::DatabaseHandler(Queue* queryQueue, Queue* responseQueue, ErrorQueue* errorQueue)
	:	connectedToDatabase(false),
		running(false),
		queueItem(),
		queryQueuePtr(queryQueue),
		responseQueuePtr(responseQueue),
		errorQueuePtr(errorQueue)
{	}

DatabaseHandler::~DatabaseHandler()
{
	stop();
}

void DatabaseHandler::start()
{
	running = true;
	DATABASE_HANDLER_THREAD = thread(&DatabaseHandler::run, this);
}

void DatabaseHandler::stop()
{
	if (DATABASE_HANDLER_THREAD.joinable())
	{
		running = false;
		DATABASE_HANDLER_THREAD.join();
	}
}

void DatabaseHandler::run()
{
	while (running)
	{
		if (queryQueuePtr->isEmpty())
		{

		}
		else
		{
			queueItem.reset(queryQueuePtr->getItem().release());
			unique_ptr<ContentInterface> content(queueItem->getContentObject());
			contentQuery.reset(static_cast<Query*>(content.get()));
			

			if (contentQuery->isResulting())
			{
				handleResultQuery();
			}
			else
			{
				handleNoResultQuery();
			}
		}
	}
}

void  DatabaseHandler::handleResultQuery()
{
	
}


void  DatabaseHandler::handleNoResultQuery()
{
	SQLString sqlString = *static_cast<SQLString*>(contentQuery->getContent());

	if (executeNoResultQuery(sqlString))
	{
		unique_ptr<ContentInterface> response = responseTranslator.generateSuccessMessage(*queueItem);
		queueItem->changeContent(response);
		responseQueuePtr->addItem(std::move(queueItem));
	}
	else
	{
		// to do throw exception
	}
}

bool DatabaseHandler::executeNoResultQuery(SQLString& query)
{
	if (connectDatabase())
	{
		try
		{
			sqlConnection->setSchema(db::schema);	// setting database to connection
			SqlPreparedStatement.reset(sqlConnection->prepareStatement(query));

			return !SqlPreparedStatement->execute();	// this strange function returns false when succeed
			
		}
		catch (SQLException&)
		{
			return false;
		}
	}
	else return false;
}

bool DatabaseHandler::connectDatabase()
{
	try
	{
		driver = unique_ptr<MySQL_Driver>(sql::mysql::get_mysql_driver_instance());
		sqlConnection = unique_ptr<Connection>( driver->connect(db::hostName, db::userName, db::password));
		return true;
	}
	catch (SQLException&)
	{
		return false;
	}
}

