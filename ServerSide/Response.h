#pragma once
#include "Content.h"
#include <string>

using std::string;

class Response
	:	public Content<string>
{
	
public:
	Response(string& content);
	~Response();
};


