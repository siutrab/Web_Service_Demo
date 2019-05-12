#pragma once
#include "QueueItem.h"
#include "jdbc/cppconn/sqlstring.h"


class NoResultQuery
	: public Content<sql::SQLString>
{

public:
	NoResultQuery(sql::SQLString& queryString);
	~NoResultQuery();
};

