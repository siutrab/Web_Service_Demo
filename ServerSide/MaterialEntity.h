#pragma once
#include <vector>
#include <memory>
#include "MappingInterface.h"

//class EntityInterface;

using std::string;
using std::vector;
using std::unique_ptr;



class MaterialEntity
	: public EntityInterface
{
public:
	MaterialEntity(
		unsigned int	id,
		float			lambda,
		float			price,
		float			priceLambda,
		unsigned short	width,
		string&			name,
		string&			link,
		string&			materialType,
		string&			producer);

	~MaterialEntity();

	string getTableName() override;

private:

	// WARNING!!! these classes are the same, but there is no way to use polymorphism or templates
	// so theere is a need for keep changing each of them during change.
	// WARNING!!! all these classes inherit from MappingInterface
	class IdColumn
		: public FieldTemplate<unsigned int>
		{
		public:
			IdColumn(unsigned int value) : FieldTemplate(value) {}
			unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("id"))); }
		};

	class LambdaColumn
		: public FieldTemplate<float>
		{
		public:
			LambdaColumn(float value) : FieldTemplate(value) {}
			unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("lambda"))); }
		};

	class PriceColumn
		: public FieldTemplate<float>
		{
		public:
			PriceColumn(float value) : FieldTemplate(value) {}
			unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("price"))); }
		};

	class PriceToLambdaColumn
		: public FieldTemplate<float>
		{
		public:

			PriceToLambdaColumn(float value) : FieldTemplate(value) {}
			unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("price_to_lambda"))); }
		};

	class WidthColumn
		: public FieldTemplate<unsigned short>
	{
	public:

		WidthColumn(unsigned short value) : FieldTemplate(value) {}
		unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("width"))); }
	};

	class NameColumn
		: public FieldTemplate<string>
		{
		public:
			NameColumn(string& value) : FieldTemplate(value) {}
			unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("name"))); }
		};	

	class LinkColumn
		: public FieldTemplate<string>
		{
		public:
			LinkColumn(string& value) : FieldTemplate(value) {}
			unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("link"))); }
		};

	class MaterialColumn
		: public FieldTemplate<string>
		{
		public:
			MaterialColumn(string& value) : FieldTemplate(value) {}
			unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("type_of_material"))); }
		};

	class ProducerColumn
		: public FieldTemplate<string>
		{
		public:
			ProducerColumn(string& value) : FieldTemplate(value) {}
			unique_ptr<string> getColumnName() override { return (unique_ptr<string>(new string("producer"))); }
		};
	// End of WARNING

};
