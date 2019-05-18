#include "Query.h"


Query::Query(sql::SQLString& queryString)
	:	Content<sql::SQLString>(queryString)

{

}


Query::~Query()
{
}
