#include "ReadMethod.h"



ReadMethod::ReadMethod(QueryGenerator* queryGenerator)
	:	queryGenerator(queryGenerator)
{
}


ReadMethod::~ReadMethod()
{	}


unique_ptr<Query> ReadMethod::generateQuery(DocumentXml& document)//////////////////////////////////// TOOOO DOOOOO
{
	SQLString s;
	return unique_ptr<Query>(new Query(s));
}

unique_ptr<string> ReadMethod::getMethodName()
{
	return std::make_unique<string>("read");
}

bool ReadMethod::isResulting()
{
	return true;
}