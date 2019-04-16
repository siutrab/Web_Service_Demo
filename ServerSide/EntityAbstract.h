#pragma once
#include "jdbc/cppconn/sqlstring.h"
#include <vector>
#include "boost/any.hpp"

using std::vector;
using std::string;

template <class T>
class ColumnAbstract
{
protected:
	T value;
public:
	// virtual void setValue(void*) = 0;
	virtual std::string getValueAsString() = 0;
	virtual std::string getName() = 0;
	T getValue() { return value; }
	void setValue(T value) { this->value = value; }
};


class ColumnType
{	

public:

};

class EntityAbstract
{
public:
	virtual vector<ColumnAbstract<void>*>* getVectorFields() = 0;
	virtual unsigned short getFieldsNumber() = 0;
	virtual std::string getTableName() = 0;
};

