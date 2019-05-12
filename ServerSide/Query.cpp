#include "Query.h"


Query::Query(sql::SQLString& queryString, bool resulting)
	:	Content<sql::SQLString>(queryString),
		resulting(resulting)
{

}


Query::~Query()
{
}

bool Query::isResulting()
{
	return resulting;
}