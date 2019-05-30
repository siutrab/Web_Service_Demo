#include "ResultSetContent.h"



ResultSetContent::ResultSetContent(shared_ptr<ResultSet>& entityVector, ReadMethodInterface* methodPtr)
	:	Content<shared_ptr<ResultSet>>(entityVector),
		method(methodPtr)
{
}


ResultSetContent::~ResultSetContent()
{
}

ReadMethodInterface* ResultSetContent::getMethod()
{
	return method;
}

