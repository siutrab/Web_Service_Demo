#pragma once
#include "QueueItem.h"
#include "RegularQueryHandler.h"
#include "ResultingQueryHandler.h"

#include "jdbc/mysql_connection.h"
#include "jdbc/mysql_driver.h"
#include "jdbc/mysql_error.h"

#include <thread>
#include <memory>

using sql::SQLString;
using sql::mysql::MySQL_Driver;
using sql::Connection;
using sql::SQLException;

using std::unique_ptr;
using std::thread;

class Server;
class Query;
class Queue;
class RegularQueryHandler;
class ResultingQueryHandler;


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


		RegularQueryHandler regularQueryHandler;
		ResultingQueryHandler resultingQueryHandler;

			bool connectedToDatabase;
			bool running;
			thread DATABASE_HANDLER_THREAD;

			// needed for connecting and executing querys;
			unique_ptr<MySQL_Driver> driver;
			unique_ptr<Connection> sqlConnection;
		
		void run();		// main loop
	public:
		DatabaseHandler(Queue* queryQueue, Queue* resultingQueryQueue, Queue* responseQueue, Queue* entityQueue, ErrorQueue* errorQueue);
		~DatabaseHandler();
		void start();
		void stop();

		bool connectDatabase();
	};

