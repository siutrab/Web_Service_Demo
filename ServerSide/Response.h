#pragma once
#include "Request.h"
class Request;
class Response
{
	Request* request;
public:
	Response();
	~Response();
};

