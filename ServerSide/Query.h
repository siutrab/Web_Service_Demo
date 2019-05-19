#pragma once
#include "QueueItem.h"
#include "EntityInterface.h"
#include "MethodInterface.h"
#include "jdbc/cppconn/sqlstring.h"

class ReadMethodInterface;

class Query
	: public Content<sql::SQLString>
{
public:
	Query(sql::SQLString& queryString);
	~Query();
};



class ResultingQuery
	: public Query
{
	ReadMethodInterface* readMethod;
public:
	ResultingQuery(sql::SQLString& queryString, ReadMethodInterface*  method);
	~ResultingQuery();
	ReadMethodInterface* getMethodPointer();

};