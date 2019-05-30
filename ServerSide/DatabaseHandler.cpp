#include "pch.h"
#include "DatabaseHandler.h"


const SQLString DatabaseHandler::DatabaseInfo::hostName = "localhost";
const SQLString DatabaseHandler::DatabaseInfo::userName = "user_for_materials";
const SQLString DatabaseHandler::DatabaseInfo::password = "haslo";
const SQLString DatabaseHandler::DatabaseInfo::schema = "building_materials";


DatabaseHandler::DatabaseHandler(Queue* queryQueue, Queue* resultingQueryQueue, Queue* responseQueue, Queue* entityQueue, ErrorHandler* errorQueue)
	:	connectedToDatabase(false),
		running(false),
		regularQueryHandler(queryQueue, responseQueue, errorQueue, this),
		resultingQueryHandler(resultingQueryQueue, entityQueue, errorQueue, this)
{
	driver.reset(sql::mysql::get_mysql_driver_instance());
}


DatabaseHandler::~DatabaseHandler()
{	}


void DatabaseHandler::start()
{
	running = true;
	DATABASE_HANDLER_THREAD = thread(&DatabaseHandler::run, this);
}


void DatabaseHandler::stop()
{
	running = false;
	bool disconnected = false;
	
	do
		disconnected = disconnectDatabase();
	while (!disconnected);
	
	if (DATABASE_HANDLER_THREAD.joinable())		// thread has to egzist to be joined
		DATABASE_HANDLER_THREAD.join();
}


void DatabaseHandler::run()
{
	while (running)
	{
		regularQueryHandler.handleQuery();
		resultingQueryHandler.handleQuery();
	}
}

bool DatabaseHandler::disconnectDatabase()
{
	if (connectedToDatabase)
	{
		try
		{
			sqlConnection->close();
			connectedToDatabase = false;
			return true;
		}
		catch(...)
		{ 
			return false;
		}
	}
}


bool DatabaseHandler::connectDatabase()
{
	std::cout << "Connectiong to database..." << std::endl;
	do
	{
		try
		{
			sqlConnection.reset( driver->connect(db::hostName, db::userName, db::password));
			sqlConnection->setSchema(db::schema);	// setting database to connection

			regularQueryHandler.setConnection(sqlConnection.get());
			resultingQueryHandler.setConnection(sqlConnection.get());
			connectedToDatabase = true;
			std::cout << "Database connected." << std::endl;
			return true;
		}
		catch (SQLException&)
		{
			connectedToDatabase = false;
		}
	} while (!connectedToDatabase);
}

