#include "MaterialEntity.h"

MaterialEntity::MaterialEntity(
	unsigned int	id,
	float			lambda,
	float			price,
	float			priceLambda,
	string&			name,
	string&			link,
	string&			materialType,
	string&			producer)
	
{	
	fieldsVector.push_back(new MaterialEntity::IdColumn(id));
	fieldsVector.push_back(new MaterialEntity::NameColumn(name));
	fieldsVector.push_back(new MaterialEntity::LambdaColumn(lambda));
	fieldsVector.push_back(new MaterialEntity::PriceColumn(price));
	fieldsVector.push_back(new MaterialEntity::MaterialColumn(materialType));
	fieldsVector.push_back(new MaterialEntity::PriceToLambdaColumn(priceLambda));
	fieldsVector.push_back(new MaterialEntity::ProducerColumn(producer));
	fieldsVector.push_back(new MaterialEntity::LinkColumn(link));
}	

MaterialEntity::~MaterialEntity()
{
	for (size_t i = 0; i < fieldsVector.size(); i++)
		delete fieldsVector[i];
}

string MaterialEntity::getTableName() { return "materials"; }

