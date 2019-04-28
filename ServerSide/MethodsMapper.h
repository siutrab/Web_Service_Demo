#pragma once
#include <memory>
#include <vector>
//#include "MethodInterface.h"
#include "CreateMethod.h"

//#include "ExceptionsSystem.h"

using std::vector;
using std::shared_ptr;
using std::unique_ptr;

class MethodInterface;
class CreateMethod;

class MethodsMapper
{
	vector<shared_ptr<MethodInterface>> MethodList;

public:
	MethodsMapper();
	~MethodsMapper();
	shared_ptr<MethodInterface> findMethod(string& name);	// WARNING!!! throws exception
};

