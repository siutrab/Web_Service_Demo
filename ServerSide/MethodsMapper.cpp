#include "MethodsMapper.h"



MethodsMapper::MethodsMapper()
	: MethodList(
		{
			shared_ptr<MethodInterface>(new CreateMethod())
		}
	)
{
}


MethodsMapper::~MethodsMapper()
{
}

shared_ptr<MethodInterface> MethodsMapper::findMethod(string& name)
{
	for (size_t i = 0; i < MethodList.size(); i++)
	{
		if (*(MethodList[i]->getMethodName()) == name)
			return MethodList[i];
	}
	throw ServerExceptions::QueryMappingExceptions::WrongMethodName();
}