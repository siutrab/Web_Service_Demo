#ifndef NON_RESULT_QUERY_H
#define NON_RESULT_QUERY_H


#pragma once
#include "Client.h"
#include "jdbc/cppconn/sqlstring.h"
using sql::SQLString;
class Client;

	class NonResultQuery
	{
		unsigned int id;
		Client* client;
		SQLString* queryString;
	public:
		NonResultQuery();
		~NonResultQuery();
	};

#endif // !NON_RESULT_QUERY_H
