#ifndef RESULT_QUERY_H
#define RESULT_QUERY_H



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


#endif // !RESULT_QUERY_H
