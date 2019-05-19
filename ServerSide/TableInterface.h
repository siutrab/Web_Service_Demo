#pragma once
#include <string>
using std::string;
class MethodsMapper;

class TableInterface
{
public:
	virtual string getTableName() = 0;
	virtual MethodsMapper* getMethodsMapper() = 0;
};

