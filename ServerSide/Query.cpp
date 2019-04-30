#include "Query.h"


Query::Query(std::string& queryString)
	: Content(sql::SQLString(queryString.c_str()))
{

}


Query::~Query()
{
}
