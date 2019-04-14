#pragma once
#include <vector>
#include "boost/any.hpp"
#include "EntityAbstract.h"

	struct IdColumn
		: ColumnAbstract
	{
		std::string getName();
	};

	struct NameColumn
		: ColumnAbstract
	{
		std::string getName();
	};

	struct LambdaColumn
		: ColumnAbstract
	{
		std::string getName();
	};

	struct PriceColumn
		: ColumnAbstract
	{
		std::string getName();
	};

	struct TypeOfMaterialColumn
		: ColumnAbstract
	{
		std::string getName();
	};

	struct PriceToLambdaColumn
		: ColumnAbstract
	{
		std::string getName();
	};

	struct ProducerColumn
		: ColumnAbstract
	{
		std::string getName();
	};

	struct LinkColumn
		: ColumnAbstract
	{
		std::string getName();
	};
	

class MaterialTable
{
protected:
		IdColumn idColumn;
		NameColumn nameColumn;
		LambdaColumn lambdaColumn;
		PriceColumn priceColumn;
		TypeOfMaterialColumn typeColumn;
		PriceToLambdaColumn priceLambdaColumn;
		ProducerColumn producerColumn;
		LinkColumn linkColumn;

public:
	std::vector<ColumnAbstract*> Fields;
	
	MaterialTable();
	~MaterialTable();
};

