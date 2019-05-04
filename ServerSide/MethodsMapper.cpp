#include "TranslatorXml.h"
#include "MethodsMapper.h"


MethodsMapper::MethodsMapper()
{
	std::unique_ptr<MethodInterface> createMethodPtr(new CreateMethod);
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