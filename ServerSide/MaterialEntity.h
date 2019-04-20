#pragma once
#include <vector>
#include <memory>
#include "MaterialEntity.h"
#include "MappingInterface.h"

using std::string;
using std::vector;
using std::unique_ptr;

class MaterialEntity
	: public EntityInterface
{
public:
	MaterialEntity(unsigned int	id,
		float			lambda,
		float			price,
		float			priceLambda,
		std::string&	name,
		std::string&	link,
		std::string&	materialType,
		std::string&	producer);

	~MaterialEntity();
	string getTableName() override;
private:
	class IdColumn
		: public FieldTemplate<unsigned int>
	{
	public:
		//IdColumn(unsigned int value) : FieldInstance("id", &value) {}
		IdColumn(unsigned int value) : FieldTemplate(value) {}
		unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("id"))); }
	};


	class LambdaColumn
		: public FieldTemplate<float>
	{
	public:
		//LambdaColumn(float value) : FieldInstance("lambda", &value) {}
		LambdaColumn(float value) : FieldTemplate(value) {}
		unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("lambda"))); }
	};


	class PriceColumn
		: public FieldTemplate<float>
	{
	public:
		/*PriceColumn(float value) : FieldInstance("price", &value) {}*/
		PriceColumn(float value) : FieldTemplate(value) {}
		unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("price"))); }
	};
	class PriceToLambdaColumn
		: public FieldTemplate<float>
	{
	public:
		//PriceToLambdaColumn(float value) : FieldInstance("price_to_lambda", &value) {}
		PriceToLambdaColumn(float value) : FieldTemplate(value) {}
		unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("price_to_lambda"))); }
	};	


	class NameColumn
		: public FieldTemplate<string>
	{
	public:
		//NameColumn(string &value) : FieldInstance("name", &value) {}
		NameColumn(string& value) : FieldTemplate(value) {}
		unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("name"))); }
	};	


	class LinkColumn
		: public FieldTemplate<string>
	{
	public:
		//LinkColumn(string &value) : FieldInstance("name", &value) {}
		LinkColumn(string& value) : FieldTemplate(value) {}
		unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("link"))); }
	};


	class MaterialColumn
		: public FieldTemplate<string>
	{
	public:
		/*MaterialColumn(string &value) : FieldInstance("type_of_material", &value) {}*/
		MaterialColumn(string& value) : FieldTemplate(value) {}
		unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("type_of_material"))); }
	};


	class ProducerColumn
		: public FieldTemplate<string>
	{
	public:
		/*ProducerColumn(string &value) : FieldInstance("producer", &value) {}*/
		ProducerColumn(string& value) : FieldTemplate(value) {}
		unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("producer"))); }
	};


};

//class MaterialEntity
//	: public EntityInterface
//{
//
//
//public:
//	MaterialEntity(unsigned int	id,
//				float			lambda, 
//				float			price, 
//				float			priceLambda, 
//				std::string&	name, 
//				std::string&	link, 
//				std::string&	materialType, 
//				std::string&	producer);
//	~MaterialEntity();
//	string getTableName() override;
//};

