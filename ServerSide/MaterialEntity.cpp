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
	fieldsVector.push_back(unique_ptr<FieldInterface>(new MaterialEntity::IdColumn				(id)));
	fieldsVector.push_back(unique_ptr<FieldInterface>(new MaterialEntity::NameColumn			(name)));
	fieldsVector.push_back(unique_ptr<FieldInterface>(new MaterialEntity::LambdaColumn			(lambda)));
	fieldsVector.push_back(unique_ptr<FieldInterface>(new MaterialEntity::PriceColumn			(price)));
	fieldsVector.push_back(unique_ptr<FieldInterface>(new MaterialEntity::MaterialColumn		(materialType)));
	fieldsVector.push_back(unique_ptr<FieldInterface>(new MaterialEntity::PriceToLambdaColumn	(priceLambda)));
	fieldsVector.push_back(unique_ptr<FieldInterface>(new MaterialEntity::ProducerColumn		(producer)));
	fieldsVector.push_back(unique_ptr<FieldInterface>(new MaterialEntity::LinkColumn			(link)));
}	

MaterialEntity::~MaterialEntity()
{
	/*for (size_t i = 0; i < fieldsVector.size(); i++)
		delete fieldsVector[i];*/
}

string MaterialEntity::getTableName() { return "materials"; }

