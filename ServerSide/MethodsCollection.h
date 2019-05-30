#pragma once
#include "QueryGenerator.h"
#include "MethodInterface.h"
#include "CreateMethod.h"
#include "ReadMethod.h"
#include <memory>
#include <vector>


using std::vector;
using std::unique_ptr;

class MethodInterface;
class CreateMethodMaterials;


class MethodsCollection
{
	QueryGenerator queryGenerator;
	vector<unique_ptr<MethodInterface>> MethodList;

public:
	MethodsCollection();
	~MethodsCollection();
	MethodInterface& findMethod(string& name);	// WARNING!!! throws exception
};

