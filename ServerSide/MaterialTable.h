#pragma once
#include <vector>
#include "boost/any.hpp"
#include "EntityAbstract.h"

using std::string;

	class IdColumn
		:	public ColumnAbstract<unsigned int>
			//public ColumnType
	{
	public:
		string getValueAsString() override;
		string getName() override;
		//void setValue(void*) override;
	};

	class NameColumn
		:	public ColumnAbstract<string>

	{

	public:
		string getValueAsString() override;
		string getName() override;
		//void setValue(void*) override;
	};

	class LambdaColumn
		: public ColumnAbstract<float>
	{
		float value;
	public:
		string getValueAsString() override;
		std::string getName() override;
		float getValue();
		//void setValue(void*) override;
	};

	//class PriceColumn
	//	: public ColumnAbstract
	//{
	//	float value;
	//public:
	//	virtual std::string getValueAsString() override;
	//	std::string getName() override;
	//	float getValue();
	//	//void setValue(void*) override;
	//};

	//class TypeOfMaterialColumn
	//	: public ColumnAbstract
	//{
	//	std::string value;
	//public:
	//	virtual std::string getValueAsString();
	//	std::string getName();
	//	std::string getValue();
	//	//void setValue(void*) override;
	//};

	//class PriceToLambdaColumn
	//	: public ColumnAbstract
	//{
	//	float value;
	//public:
	//	virtual std::string getValueAsString() override;
	//	std::string getName() override;
	//	float getValue();
	//	//void setValue(void*) override;
	//};

	//class ProducerColumn
	//	: public ColumnAbstract
	//{
	//	std::string value;
	//public:
	//	virtual std::string getValueAsString() override;
	//	std::string getName() override;
	//	std::string getValue();
	//	//void setValue(void*) override;
	//};

	//class LinkColumn
	//	: public ColumnAbstract
	//{
	//	std::string value;
	//public:
	//	virtual std::string getValueAsString() override;
	//	std::string getName() override;
	//	std::string getValue();
	//	//void setValue(void*) override;
	//};
	

class MaterialTable
{
protected:
		IdColumn idColumn;
		NameColumn nameColumn;
		LambdaColumn lambdaColumn;
		/*PriceColumn priceColumn;
		TypeOfMaterialColumn typeColumn;
		PriceToLambdaColumn priceLambdaColumn;
		ProducerColumn producerColumn;
		LinkColumn linkColumn;*/

	std::vector<ColumnAbstract<void>> Fields;
public:
	std::vector<ColumnAbstract<void>>* getFields();
	MaterialTable();
	~MaterialTable();
};

