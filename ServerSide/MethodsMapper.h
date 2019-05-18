#pragma once
#include <memory>
#include <vector>
#include "QueryGenerator.h"
#include "MethodInterface.h"
#include "CreateMethod.h"
#include "ReadMethod.h"


using std::vector;
using std::unique_ptr;

class MethodInterface;
class CreateMethod;


class MethodsMapper
{
	QueryGenerator queryGenerator;
	vector<unique_ptr<MethodInterface>> MethodList;

public:
	MethodsMapper();
	~MethodsMapper();
	MethodInterface& findMethod(string& name);	// WARNING!!! throws exception
};

