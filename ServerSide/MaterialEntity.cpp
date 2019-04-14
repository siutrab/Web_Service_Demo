#include "pch.h"
#include "MaterialEntity.h"

//enum class MaterialTypes
//	: std::int8_t
//{
//	wool,
//	polistyrene,
//	polistyreneXPS,
//	PIR,
//	PUR
//};

//Material::Material(unsigned int id, float lambda, float price, std::string& name, std::string& link, MaterialTypes materialType)
//	:	id(id),
//		lambda(lambda),
//		price(price),
//		name(*name),
//		link(*link),
//		materialType(materialType)
//{
//	Fields.push_back(id);
//	Fields.push_back(lambda);
//	Fields.push_back(price);
//	Fields.push_back(name);
//	Fields.push_back(link);
//	Fields.push_back(materialType);
//}




MaterialEntity::MaterialEntity(unsigned int id, float lambda, float price, std::string& name, std::string& link, std::string& materialType, std::string& producer)
	: materialTable(new MaterialTable)
{
	materialTable->Fields[0]->value = id;				// 0	"id"
	materialTable->Fields[1]->value = name;				// 1	"name",
	materialTable->Fields[2]->value = lambda;			// 2	"lambda",
	materialTable->Fields[3]->value = price;			// 3	"price",
	materialTable->Fields[4]->value = materialType;		// 4	"type_of_material",
	materialTable->Fields[5]->value = price / lambda;	// 5	"price_to_lambda",
	materialTable->Fields[6]->value = producer;			// 6	"producer",
	materialTable->Fields[7]->value = link;				// 7	"link"

	std::cout << materialTable->Fields[0]->getName() << std::endl;
	std::cout << materialTable->Fields[1]->getName() << std::endl;
	std::cout << materialTable->Fields[2]->getName() << std::endl;
	std::cout << materialTable->Fields[3]->getName() << std::endl;
}


MaterialEntity::~MaterialEntity()
{	}

//std::vector<ColumnAbstract*>* MaterialEntity::getVectorFields() 
//{ 
//	return &materialTable->Fields;
//}

unsigned short MaterialEntity::getFieldsNumber() { return materialTable->Fields.size(); }

// Getters dependent on Fields
unsigned int MaterialEntity::getId()			{ return boost::any_cast<unsigned int>		(materialTable->Fields[0]->value); }

std::string MaterialEntity::getName()			{ return boost::any_cast<std::string>		(materialTable->Fields[1]->value); }

float MaterialEntity::getLambda()				{ return boost::any_cast<float>				(materialTable->Fields[2]->value); }

float MaterialEntity::getPrice()				{ return boost::any_cast<float>				(materialTable->Fields[3]->value); }

std::string MaterialEntity::getMaterialType()	{ return boost::any_cast<std::string>		(materialTable->Fields[4]->value); }

float MaterialEntity::getPriceToLambda()		{ return boost::any_cast<float>				(materialTable->Fields[5]->value); }

std::string MaterialEntity::getProducer()		{ return boost::any_cast<std::string>		(materialTable->Fields[6]->value); }

std::string MaterialEntity::getLink()			{ return boost::any_cast<std::string>		(materialTable->Fields[4]->value); }


float MaterialEntity::getU(unsigned char width) { return (boost::any_cast<float>(materialTable->Fields[2]->value) / width); }

std::string MaterialEntity::getTableName() { return "materials"; }
