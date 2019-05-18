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
		regularQueryHanler(queryQueue, responseQueue, errorQueue, this)
{
	driver.reset(sql::mysql::get_mysql_driver_instance());
}

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
	sqlConnection->close();

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
		regularQueryHanler.handleQuery();
		
	}
}

bool DatabaseHandler::connectDatabase()
{
	try
	{
		sqlConnection.reset( driver->connect(db::hostName, db::userName, db::password));
		sqlConnection->setSchema(db::schema);	// setting database to connection

		regularQueryHanler.setConnection(sqlConnection.get());
		return true;
	}
	catch (SQLException&)
	{
		return false;
	}
}

Connection* DatabaseHandler::getConnection()
{
	return sqlConnection.get();
}
