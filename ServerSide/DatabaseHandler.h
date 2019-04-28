#pragma once
#include "jdbc/mysql_connection.h"
#include "jdbc/mysql_driver.h"
#include "jdbc/mysql_error.h"

#include "jdbc/cppconn/statement.h"
#include "jdbc/cppconn/prepared_statement.h"

#include "MaterialEntity.h"
#include "QueryGenerator.h"

#include <thread>
#include <memory>
using std::string;
using sql::SQLString;
using sql::mysql::MySQL_Driver;
using sql::Connection;
using sql::PreparedStatement;
using sql::SQLException;
using std::unique_ptr;
using::std::thread;


//class EntityInterface;
//class MaterialEntity;
class Server;
class QueryGenerator;



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
			bool running;
			thread DATABASE_HANDLER_THREAD;

			QueryGenerator* queryGenerator;

			// needed for connecting and executing querys;
			unique_ptr<MySQL_Driver> driver;
			unique_ptr<Connection> sqlConnection;
			unique_ptr<PreparedStatement> SqlPreparedStatement;
	
			//static QueryQueue* queryQueue;
			//Server* server;
			
		void run();		// main loop
		void connectDatabase();
		bool disconnectDatabase();
	public:
		DatabaseHandler();
		~DatabaseHandler();
		void start();
		void stop();
		bool executeQuery(SQLString& query);
	
		bool connectionIsValid();
		
		//static void setQueryQueuePointer(QueryQueue* pointer);
	};

