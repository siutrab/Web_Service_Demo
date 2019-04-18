#include "MaterialEntity.h"



MaterialEntity::MaterialEntity(
	unsigned int	id,
	float			lambda,
	float			price,
	float			priceLambda,
	std::string&	name,
	std::string&	link,
	std::string&	materialType,
	std::string&	producer)
{
	fieldsVector.push_back(new FieldInstance<unsigned int>("id", &id));						// 0	"id"
	fieldsVector.push_back(new FieldInstance<string>("name", &name));						// 1	"name"
	fieldsVector.push_back(new FieldInstance<float>("lambda", &lambda));						// 2	"lambda"
	fieldsVector.push_back(new FieldInstance<float>("price", &price));						// 3	"price",
	fieldsVector.push_back(new FieldInstance<string>("type_of_material", &materialType));	// 4	"type_of_material",
	fieldsVector.push_back(new FieldInstance<float>("price_to_lambda", &priceLambda));		// 5	"price_to_lambda"
	fieldsVector.push_back(new FieldInstance<string>("producer", &producer));				// 6	"producer"
	fieldsVector.push_back(new FieldInstance<string>("link", &link));						// 7	"link"

}


MaterialEntity::~MaterialEntity()
{
	for (size_t i = 0; i < fieldsVector.size(); i++)
		delete fieldsVector[i];
}

string MaterialEntity::getTableName() { return "meterials"; }

