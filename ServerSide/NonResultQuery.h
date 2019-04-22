#pragma once
#include "Client.h"

using sql::SQLString;

	class NonResultQuery
	{
		unsigned int id;
		Client* client;
		SQLString* queryString;
	public:
		NonResultQuery();
		~NonResultQuery();
	};

