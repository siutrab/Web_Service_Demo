#pragma once
#include "Client.h"
#include "jdbc/cppconn/sqlstring.h"
class Client;

class Query
{
	unsigned int id;
	Client* client;
	sql::SQLString* queryString;
public:
	Query();
	~Query();
};

