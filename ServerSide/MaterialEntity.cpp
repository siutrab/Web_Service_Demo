#include "pch.h"
#include "MaterialEntity.h"

MaterialEntity::MaterialEntity(unsigned int id, float lambda, float price, std::string& name, std::string& link, std::string& materialType, std::string& producer)
	:	materialTable(new MaterialTable),
		Fields(materialTable->getFields())
{
	(*Fields)[0]->value = id;				// 0	"id"
	(*Fields)[1]->value = name;				// 1	"name",
	(*Fields)[2]->value = lambda;			// 2	"lambda",
	(*Fields)[3]->value = price;			// 3	"price",
	(*Fields)[4]->value = materialType;		// 4	"type_of_material",
	(*Fields)[5]->value = price / lambda;	// 5	"price_to_lambda",
	(*Fields)[6]->value = producer;			// 6	"producer",
	(*Fields)[7]->value = link;				// 7	"link"

	/*std::cout << materialTable->Fields[0]->getName() << std::endl;
	std::cout << materialTable->Fields[1]->getName() << std::endl;
	std::cout << materialTable->Fields[2]->getName() << std::endl;
	std::cout << materialTable->Fields[3]->getName() << std::endl;*/
}


MaterialEntity::~MaterialEntity()
{	}

std::vector<ColumnAbstract*>* MaterialEntity::getVectorFields() 
{ 
	return Fields;
}

unsigned short MaterialEntity::getFieldsNumber() { return (*Fields).size(); }

// Getters dependent on Fields
unsigned int MaterialEntity::getId()			{ return boost::any_cast<unsigned int>		((*Fields)[0]->value); }

std::string MaterialEntity::getName()			{ return boost::any_cast<std::string>		((*Fields)[1]->value); }

float MaterialEntity::getLambda()				{ return boost::any_cast<float>				((*Fields)[2]->value); }

float MaterialEntity::getPrice()				{ return boost::any_cast<float>				((*Fields)[3]->value); }

std::string MaterialEntity::getMaterialType()	{ return boost::any_cast<std::string>		((*Fields)[4]->value); }

float MaterialEntity::getPriceToLambda()		{ return boost::any_cast<float>				((*Fields)[5]->value); }

std::string MaterialEntity::getProducer()		{ return boost::any_cast<std::string>		((*Fields)[6]->value); }

std::string MaterialEntity::getLink()			{ return boost::any_cast<std::string>		((*Fields)[4]->value); }


float MaterialEntity::getU(unsigned char width) { return (boost::any_cast<float>((*Fields)[2]->value) / width); }

std::string MaterialEntity::getTableName() { return "materials"; }
