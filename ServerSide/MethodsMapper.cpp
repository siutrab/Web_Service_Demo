//#include "QueryGenerator.h"
#include "TranslatorXml.h"
#include "MethodsMapper.h"


MethodsMapper::MethodsMapper()
	:	queryGenerator()
{
	std::unique_ptr<MethodInterface> createMethodPtr(new CreateMethod(&queryGenerator));
	MethodList.push_back(std::move(createMethodPtr));
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