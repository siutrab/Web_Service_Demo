#include "NoResultQuery.h"


NoResultQuery::NoResultQuery(sql::SQLString& queryString)
	: Content<sql::SQLString>(queryString)
{

}


NoResultQuery::~NoResultQuery()
{
}
