#include "pch.h"
#include "DatabaseHandler.h"


DatabaseHandler::DatabaseHandler()
	:	connected(false)
{
	
}


DatabaseHandler::~DatabaseHandler()
{
}

bool DatabaseHandler::connectDatabase()
{
	//sql::mysql::MySQL_Driver* driver;
	//sql::Connection* connection;
	driver = sql::mysql::get_mysql_driver_instance();
	try
	{
		connection = driver->connect("localhost", "user_for_materials", "haslo");
	}
	catch (sql::SQLException e)
	{

	}
	try
	{
		connection->setSchema("building_materials");
		sql::PreparedStatement* prepStatement;
		prepStatement = connection->prepareStatement("INSERT INTO `materials`(`id`, `name`, `lambda`, `price`, `type_of_material`, `price_to_lambda`, `producer`, `link`) VALUES (NULL,\"ROCKTON\",0.037, 100, \"wool\", 2700, \"ROCKWOOL\", \"http\")");
		prepStatement->execute();
		delete connection;

	}
	catch (sql::SQLException e)
	{
		std::cout << e.getErrorCode();
	}

	// delete driver; shouldn't be used, connection frees it.
	return false;
}