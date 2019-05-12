#include "pch.h"
#include "DatabaseHandler.h"



QueryQueue* DatabaseHandler::queryQueuePtr;

void DatabaseHandler::setQueryQueuePtr(QueryQueue* pointer)
{
	DatabaseHandler::queryQueuePtr = pointer; // Settet in QueryQueue object
	const_cast<const QueryQueue*>(DatabaseHandler::queryQueuePtr);
}




DatabaseHandler::DatabaseHandler()
	:	connectedToDatabase(false),
		running(false),
		queueItem()
{	

}

void DatabaseHandler::start()
{
	running = true;
	DATABASE_HANDLER_THREAD = thread(&DatabaseHandler::run, this);
}
void DatabaseHandler::stop()
{
	running = false;
	DATABASE_HANDLER_THREAD.join();
}

DatabaseHandler::~DatabaseHandler()
{	}

void DatabaseHandler::run()
{
	while (running)
	{
		handleNoResultQuery();
		handleResultQuery();
	}
}

void  DatabaseHandler::handleResultQuery()
{
	
}


void  DatabaseHandler::handleNoResultQuery()
{
	if (queryQueuePtr->isEmpty())
	{

	}
	else
	{
		auto queryItem = queryQueuePtr->getItem();
		queueItem.swap(queryItem);

		SQLString sqlString = *static_cast<SQLString*>(queueItem->getContent());

		std::cout << executeNoResultQuery(sqlString);
	}
}

bool DatabaseHandler::executeNoResultQuery(SQLString& query)
{
	connectDatabase();
	if (connectionIsValid())
	{
		try
		{
			sqlConnection->setSchema(db::schema);	// setting database to connection
			SqlPreparedStatement.reset(sqlConnection->prepareStatement(query));
			/*unique_ptr<sql::ResultSet> result;
			result.reset(SqlPreparedStatement->executeQuery());*/
			SqlPreparedStatement->execute();
			//std::cout <<std::endl << "bdbrdt " << result << std::endl;
			return true;
		}
		catch (SQLException& e)
		{

			std::cout << "error: " << e.getErrorCode();
			return false;
		}
	}
	else return false;
}

void DatabaseHandler::connectDatabase()
{
	try
	{
		driver = unique_ptr<MySQL_Driver>(sql::mysql::get_mysql_driver_instance());
		sqlConnection = unique_ptr<Connection>( driver->connect(db::hostName, db::userName, db::password));
		connectedToDatabase = true;
	}
	catch (SQLException e)
	{
		connectedToDatabase = false;
	}
}

bool DatabaseHandler::connectionIsValid() { return connectedToDatabase; }

// static members
const SQLString DatabaseHandler::DatabaseInfo::hostName = "localhost";
const SQLString DatabaseHandler::DatabaseInfo::userName = "user_for_materials";
const SQLString DatabaseHandler::DatabaseInfo::password = "haslo";
const SQLString DatabaseHandler::DatabaseInfo::schema = "building_materials";