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

