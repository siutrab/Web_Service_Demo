#pragma once
#include "MaterialEntity.h"
#include "Queue.h"
#include "Query.h"
#include "QueueItem.h"
#include "Content.h"
#include "ErrorQueue.h"
#include "ResponseTranslator.h"

#include "jdbc/mysql_connection.h"
#include "jdbc/cppconn/resultset.h"
#include "jdbc/mysql_driver.h"
#include "jdbc/mysql_error.h"
#include "jdbc/cppconn/statement.h"
#include "jdbc/cppconn/prepared_statement.h"

#include <thread>
#include <memory>

using std::string;
using sql::SQLString;
using sql::mysql::MySQL_Driver;
using sql::Connection;
using sql::PreparedStatement;
using sql::SQLException;
using sql::ResultSet;
using std::unique_ptr;
using std::thread;

class Server;
class Query;
class QueueItem;
class ErrorQueue;
class Queue;


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

		ResponseTranslator responseTranslator;

			bool connectedToDatabase;
			bool running;
			thread DATABASE_HANDLER_THREAD;

			unique_ptr<QueueItem> queueItem;
			unique_ptr<Query> contentQuery;

			// needed for connecting and executing querys;
			unique_ptr<MySQL_Driver> driver;
			unique_ptr<Connection> sqlConnection;
			unique_ptr<PreparedStatement> SqlPreparedStatement;
			unique_ptr<ResultSet> resultSet;
	
			//Server* server;
			
		Queue* queryQueuePtr;
		Queue* responseQueuePtr;
		ErrorQueue* errorQueuePtr;
		void run();		// main loop
		bool connectDatabase();
		
		void handleResultQuery();
		void handleNoResultQuery();

	public:
		DatabaseHandler(Queue* queryQueue, Queue* responseQueue, ErrorQueue* errorQueue); 
		~DatabaseHandler();
		void start();
		void stop();
		bool executeNoResultQuery(SQLString& query);

	};

