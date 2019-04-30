#pragma once
#include "jdbc/cppconn/sqlstring.h"
#include "QueueItem.h"

//class Client;

class Query
	: public Content<sql::SQLString>
{

public:
	Query(std::string& queryString);
	~Query();
};

