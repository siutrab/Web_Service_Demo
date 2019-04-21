#include "pch.h"
#include "DatabaseHandler.h"


DatabaseHandler::DatabaseHandler()
	:	connectedToDatabase(false),
		running(false)
{	
	DATABASE_HANDLER_THREAD = thread(&DatabaseHandler::start, this);

}

QueryQueue* DatabaseHandler::queryQueue;
void DatabaseHandler::setQueryQueuePointer(QueryQueue* pointer)
{
	queryQueue = pointer;
	const_cast<QueryQueue* const>(queryQueue);
}

DatabaseHandler::~DatabaseHandler()
{	}

void DatabaseHandler::start()
{
	
	running = true;
	while (running)
	{
		if (queryQueue->isEmpty())
		{
			
		}
		else
		{
			SQLString* query = queryQueue->getItem();
			executeQuery(*query);
		}
	}
}

bool DatabaseHandler::executeQuery(SQLString& query)
{
	connectDatabase();
	if (connectionIsValid())
	{
		try
		{
			sqlConnection->setSchema(db::schema);	// setting database to connection
			SqlPreparedStatement = unique_ptr<PreparedStatement>(sqlConnection->prepareStatement(query));
			SqlPreparedStatement->execute();
			return true;
		}
		catch (SQLException e)
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