#pragma once
//#include "boost/shared_ptr.hpp"
//#include "boost/scoped_ptr.hpp"
//#include "mysqlx/xdevapi.h"
#include "jdbc/mysql_connection.h"
#include "jdbc/mysql_driver.h"
#include "jdbc/mysql_error.h"

#include "jdbc/cppconn/statement.h"
#include "jdbc/cppconn/prepared_statement.h"


class sql::mysql::MySQL_Statement;
class DatabaseHandler
{
		bool connected;
		sql::mysql::MySQL_Driver* driver;
		sql::Connection* connection;
public:
	bool connectDatabase();
	bool deconnectDatabase();
	DatabaseHandler();
	~DatabaseHandler();
	bool isConnected();
	void addMaterial();
	void removeMaterial();
	void getMaterial();
};

