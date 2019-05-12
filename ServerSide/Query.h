#pragma once
#include "QueueItem.h"
#include "jdbc/cppconn/sqlstring.h"


class Query
	: public Content<sql::SQLString>
{
	bool resulting;
public:
	Query(sql::SQLString& queryString, bool resulting);
	~Query();
	bool isResulting();
};

