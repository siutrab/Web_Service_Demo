#pragma once
#include <string>
#include <utility>
#include <vector>
#include "MappingInterface.h"
#include "Query.h"

using std::string;

class ArgumentInterface
{
public:
	virtual void* getValue() = 0;
	virtual string& name() = 0;
};


template<typename T>
class Argument
	: public ArgumentInterface
{
	T value;
public:
	T* getValue() override { return &value; }
};


class MethodInterface
{
protected:
	typedef std::pair<string&, ArgumentInterface> argument;
	static unsigned short numberOfArguments;
	std::vector<argument> argumentsArray;

public:
	virtual std::vector<argument>* getArguments() = 0;
	virtual ~MethodInterface() = 0;
};


class ResultMethodInterface
	: public MethodInterface
{
public:
	virtual Query* generateQuery() = 0;
};


class NonResultMethodInterface
	: public MethodInterface
{
public:
	virtual EntityInterface* createEntities() = 0;
};