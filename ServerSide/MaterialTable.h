#pragma once
#include <vector>
#include "boost/any.hpp"
#include "EntityAbstract.h"

	class IdColumn
		: public ColumnAbstract
	{
		unsigned int value;
	public:
		virtual std::string getValueAsString();
		std::string getName();
		unsigned int getValue();
	};

	class NameColumn
		: public ColumnAbstract
	{
		std::string value;
	public:
		virtual std::string getValueAsString();
		std::string getName();
		std::string getValue();
	};

	class LambdaColumn
		: public ColumnAbstract
	{
		float value;
	public:
		virtual std::string getValueAsString();
		std::string getName();
		float getValue();
	};

	class PriceColumn
		: public ColumnAbstract
	{
		float value;
	public:
		virtual std::string getValueAsString();
		std::string getName();
		float getValue();
	};

	class TypeOfMaterialColumn
		: public ColumnAbstract
	{
		std::string value;
	public:
		virtual std::string getValueAsString();
		std::string getName();
		std::string getValue();
	};

	class PriceToLambdaColumn
		: public ColumnAbstract
	{
		float value;
	public:
		virtual std::string getValueAsString();
		std::string getName();
		float getValue();
	};

	class ProducerColumn
		: public ColumnAbstract
	{
		std::string value;
	public:
		virtual std::string getValueAsString();
		std::string getName();
		std::string getValue();
	};

	class LinkColumn
		: public ColumnAbstract
	{
		std::string value;
	public:
		virtual std::string getValueAsString();
		std::string getName();
		std::string getValue();
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

	std::vector<ColumnAbstract*> Fields;
public:
	std::vector<ColumnAbstract*>* getFields();
	MaterialTable();
	~MaterialTable();
};

