#pragma once
#include "pugixml.hpp"
#include <string>

using std::string;
using pugi::xml_document;

class MethodInterface
{
public:
	virtual void printResponse(string& response) = 0;
};
