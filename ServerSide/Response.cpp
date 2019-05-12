#include "pch.h"
#include "Response.h"


Response::Response(string& content)
	: Content<string>(content)
{
}


Response::~Response()
{
}
