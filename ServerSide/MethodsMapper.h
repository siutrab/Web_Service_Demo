#pragma once
#include <memory>
#include <vector>
#include "QueryGenerator.h"
#include "MethodInterface.h"
#include "CreateMethod.h"


using std::vector;
//using std::shared_ptr;
using std::unique_ptr;

class MethodInterface;
class CreateMethod;
//class QueryGenerator;

class MethodsMapper
{
	QueryGenerator queryGenerator;
	vector<unique_ptr<MethodInterface>> MethodList;

public:
	MethodsMapper();
	~MethodsMapper();
	MethodInterface& findMethod(string& name);	// WARNING!!! throws exception
};

