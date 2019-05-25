#pragma once
#include <string>
using std::string;
class MethodsCollection;

class TableInterface
{
public:
	virtual string getTableName() = 0;
	virtual MethodsCollection* getMethodsMapper() = 0;
};

