#pragma once
#include "QueueItem.h"
#include "jdbc/cppconn/sqlstring.h"


class Query
	: public Content<sql::SQLString>
{
public:
	Query(sql::SQLString& queryString);
	~Query();
};

