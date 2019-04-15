#include "pch.h"
#include "DatabaseHandler.h"


DatabaseHandler::DatabaseHandler()
	:	connectedToDatabase(false)
{	}


DatabaseHandler::~DatabaseHandler()
{	}

bool DatabaseHandler::executeQuery(sql::SQLString* query)
{
	connectDatabase();
	if (connectionIsValid())
	{
		
		try
		{
			connection->setSchema(db::schema);	// setting database to connection
			//preparedStatement = connection->prepareStatement("INSERT INTO `materials`(`id`, `name`, `lambda`, `price`, `type_of_material`, `price_to_lambda`, `producer`, `link`) VALUES (NULL,\"ROCKTON\",0.037, 100, \"wool\", 2700, \"ROCKWOOL\", \"http\")");
			preparedStatement = connection->prepareStatement(*query);
			preparedStatement->execute();
			delete connection;
			delete query;
			return true;
		}
		catch (sql::SQLException e)
		{
			delete connection;
			delete query;
			delete preparedStatement;
			std::cout << "error: " << e.getErrorCode();
			return false;
		}
	}
	else return false;
}

void DatabaseHandler::connectDatabase()
{
	//sql::mysql::MySQL_Driver* driver;
	//sql::Connection* connection;
	try
	{
		driver = sql::mysql::get_mysql_driver_instance();
		connection = driver->connect(db::hostName, db::userName, db::password);
		connectedToDatabase = true;
	}
	catch (sql::SQLException e)
	{
		connectedToDatabase = false;
	}
}

bool DatabaseHandler::connectionIsValid() { return connectedToDatabase; }


const sql::SQLString DatabaseHandler::DatabaseInfo::hostName = "localhost";
const sql::SQLString DatabaseHandler::DatabaseInfo::userName = "user_for_materials";
const sql::SQLString DatabaseHandler::DatabaseInfo::password = "haslo";
const sql::SQLString DatabaseHandler::DatabaseInfo::schema = "building_materials";