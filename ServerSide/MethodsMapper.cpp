#include "MaterialTable.h"
#include "MethodsMapper.h"


MethodsMapper::MethodsMapper()
	:	queryGenerator()
{
	unique_ptr<MethodInterface> createMethodPtr(new CreateMethodMaterials(&queryGenerator));
	MethodList.push_back(std::move(createMethodPtr));

	unique_ptr<MethodInterface> readMethodPtr(new ReadMethodMaterials(&queryGenerator));
	MethodList.push_back(std::move(readMethodPtr));
}


MethodsMapper::~MethodsMapper()
{
}

MethodInterface& MethodsMapper::findMethod(string& name)
{
	for (size_t i = 0; i < MethodList.size(); i++)
	{
		if (*MethodList[i]->getMethodName() == name)
			return *MethodList[i];
	}
	throw ServerExceptions::QueryMappingExceptions::WrongMethodName();
}