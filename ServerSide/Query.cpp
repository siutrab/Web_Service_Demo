#include "Query.h"


Query::Query(std::string& queryString)
	: Content<sql::SQLString>(sql::SQLString(queryString.c_str()))
{

}


Query::~Query()
{
}
