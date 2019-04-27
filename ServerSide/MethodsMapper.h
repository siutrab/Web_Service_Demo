#pragma once
#include "CreateMethod.h"
class MethodsMapper
{
	vector<shared_ptr<MethodInterface>> MethodList;

public:
	MethodsMapper();
	~MethodsMapper();
	shared_ptr<MethodInterface> findMethod(string& name);	// WARNING!!! throws exception
};

