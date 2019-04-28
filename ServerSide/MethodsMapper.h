#pragma once
#include <memory>
#include <vector>
#include "CreateMethod.h"

using std::vector;
using std::shared_ptr;

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

