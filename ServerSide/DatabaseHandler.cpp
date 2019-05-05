#include "pch.h"
#include "DatabaseHandler.h"

////////
bool DatabaseHandler::disconnectDatabase() { return false; }


//////
QueryQueue* DatabaseHandler::queryQueuePtr;

void DatabaseHandler::setQueryQueuePtr(QueryQueue* pointer)
{
	DatabaseHandler::queryQueuePtr = pointer; // Settet in QueryQueue object
	const_cast<const QueryQueue*>(DatabaseHandler::queryQueuePtr);
}


DatabaseHandler::DatabaseHandler()
	:	connectedToDatabase(false),
		running(false),
		//queryGenerator(new QueryGenerator(this)),
		queueItem()
{	

}

void DatabaseHandler::start()
{
	DATABASE_HANDLER_THREAD = thread(&DatabaseHandler::run, this);
}
void DatabaseHandler::stop()
{
	running = false;
	DATABASE_HANDLER_THREAD.join();
}

DatabaseHandler::~DatabaseHandler()
{	}

void DatabaseHandler::run()
{
	running = true;
	while (running)
	{
		if(queryQueuePtr->isEmpty())
		{

		}
		else
		{
			auto queryItem = queryQueuePtr->getItem();
			queueItem.swap(queryItem);

			SQLString sqlString = *static_cast<SQLString*>(queueItem->getContent());

			executeQuery(sqlString);
			/*queueItem.reset(queryQueuePtr->getItem().release());
			ContentInterface* content = queueItem->getContentObject().release();
*/
			//Query* query = static_cast<Query*>(content);
			//sql::SQLString sqlString = query->getContent();
			//executeQuery(sqlString);
		}
		/*unique_ptr<SQLString> query = queryGenerator->insert();
		executeQuery(*query);*/
	}
}

bool DatabaseHandler::executeQuery(SQLString& query)
{
	connectDatabase();
	if (connectionIsValid())
	{
		try
		{
			sqlConnection->setSchema(db::schema);	// setting database to connection
			SqlPreparedStatement = unique_ptr<PreparedStatement>(sqlConnection->prepareStatement(query));
			SqlPreparedStatement->execute();
			return true;
		}
		catch (SQLException e)
		{

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
		driver = unique_ptr<MySQL_Driver>(sql::mysql::get_mysql_driver_instance());
		sqlConnection = unique_ptr<Connection>( driver->connect(db::hostName, db::userName, db::password));
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