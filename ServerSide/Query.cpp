#include "Query.h"


Query::Query(sql::SQLString& queryString)
	:	Content<sql::SQLString>(queryString)

{	}


Query::~Query()
{	}




ResultingQuery::~ResultingQuery()
{	}


ResultingQuery::ResultingQuery(sql::SQLString& queryString, ReadMethodInterface*  method)
	:	Query(queryString),
		readMethod(method)
{	}


ReadMethodInterface* ResultingQuery::getMethodPointer()
{
	return readMethod;
}