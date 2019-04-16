#include "pch.h"
#include "DatabaseHandler.h"


DatabaseHandler::DatabaseHandler()
	:	connectedToDatabase(false)
{	}


DatabaseHandler::~DatabaseHandler()
{	}

bool DatabaseHandler::executeQuery(SQLString* query)
{
	connectDatabase();
	if (connectionIsValid())
	{
		
		try
		{
			sqlConnection->setSchema(db::schema);	// setting database to connection
			SqlPreparedStatement = sqlConnection->prepareStatement(*query);
			SqlPreparedStatement->execute();
			delete sqlConnection;
			delete query;
			return true;
		}
		catch (SQLException e)
		{
			delete sqlConnection;
			delete query;
			delete SqlPreparedStatement;
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
		driver = sql::mysql::get_mysql_driver_instance();
		sqlConnection = driver->connect(db::hostName, db::userName, db::password);
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