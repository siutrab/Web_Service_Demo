#pragma once
#include "jdbc/mysql_connection.h"
#include "jdbc/mysql_driver.h"
#include "jdbc/mysql_error.h"

#include "jdbc/cppconn/statement.h"
#include "jdbc/cppconn/prepared_statement.h"

#include "MaterialEntity.h"

class MaterialEntity;


class DatabaseHandler
{
	struct DatabaseInfo
	{
		static const sql::SQLString hostName;
		static const sql::SQLString userName;
		static const sql::SQLString password;
		static const sql::SQLString schema;		// name of database
	};
	typedef DatabaseHandler::DatabaseInfo db;

		bool connectedToDatabase;

		// needed for connecting and executing querys;
		sql::mysql::MySQL_Driver* driver;
		sql::Connection* connection;
		sql::PreparedStatement* preparedStatement;
	
	void connectDatabase();
	bool deconnectDatabase();
public:
	DatabaseHandler();
	~DatabaseHandler();
	bool executeQuery(sql::SQLString query);
	
	bool connectionIsValid();
	void addMaterial();
	void removeMaterial();
	void getMaterial();
};

