#pragma once
#include "Client.h"
#include "jdbc/cppconn/sqlstring.h"
class Client;

class ResultQuery
{
	unsigned int id;
	Client* client;
	sql::SQLString* queryString;
public:
	ResultQuery();
	~ResultQuery();
};
