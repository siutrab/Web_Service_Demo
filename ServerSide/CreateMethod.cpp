#include "CreateMethod.h"

typedef shared_ptr<ParameterInterface> parameter;

CreateMethod::ParametersCollection CreateMethod::parametersCollection;

std::vector<parameter> CreateMethod::parametersList
{
	parameter(new Parameter<float>(parametersCollection.lambda)),
	parameter(new Parameter<float>(parametersCollection.price)),
	parameter(new Parameter<unsigned short>(parametersCollection.width)),
	parameter(new Parameter<string>(parametersCollection.link)),
	parameter(new Parameter<string>(parametersCollection.materialType)),
	parameter(new Parameter<string>(parametersCollection.name)),
	parameter(new Parameter<string>(parametersCollection.producer))
};



CreateMethod::CreateMethod()
{
}


CreateMethod::~CreateMethod()
{
}

void CreateMethod::mapArguments(DocumentXml& document)
{
	string parentNodeName = "method";
	
	for (size_t i = 0; i < parametersList.size(); i++)
	{
		try
		{
			unique_ptr<string> parameterValue = document.getNodeValue(parametersList[i]->getName(), parentNodeName);
			parametersList[i]->setValue(*parameterValue);
		}
		catch (ExceptionInterface& e)
		{
			document.recognizeInvalid();
			document.addException(e);
		}
	}
}

unique_ptr<string> CreateMethod::getMethodName()
{
	return unique_ptr<string>(new string("create"));
}