#pragma once
#include "jdbc/mysql_connection.h"
#include "jdbc/mysql_driver.h"
#include "jdbc/mysql_error.h"

#include "jdbc/cppconn/statement.h"
#include "jdbc/cppconn/prepared_statement.h"

#include "MaterialEntity.h"

using std::string;
using sql::SQLString;
using sql::mysql::MySQL_Driver;
using sql::Connection;
using sql::PreparedStatement;
using sql::SQLException;

class MaterialEntity;

	class DatabaseHandler
	{
		struct DatabaseInfo
		{
			static const SQLString hostName;
			static const SQLString userName;
			static const SQLString password;
			static const SQLString schema;		// name of database
		};
		typedef DatabaseHandler::DatabaseInfo db;

			bool connectedToDatabase;

			// needed for connecting and executing querys;
			MySQL_Driver* driver;
			Connection* sqlConnection;
			PreparedStatement* SqlPreparedStatement;
	
		void connectDatabase();
		bool disconnectDatabase();
	public:
		DatabaseHandler();
		~DatabaseHandler();
		bool executeQuery(SQLString* query);
	
		bool connectionIsValid();
		void addEntity();
		void removeEntity();
		void getMaterial();
	};

