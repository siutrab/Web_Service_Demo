#pragma once
#include <string>
#include "EntityAbstract.h"
#include "boost/any.hpp"
#include <vector>
#include "MaterialTable.h"


class MaterialEntity 
	:	public	EntityAbstract
{
	MaterialTable* materialTable;
	vector<ColumnAbstract<void>*>* Fields;
public:
	
	MaterialEntity(unsigned int id, float lambda, float price, float priceLambda, std::string& name, std::string& link, std::string& materialType, std::string& producer);
	~MaterialEntity();
	
	// Getters dependent on Fields vector
	unsigned int getId();
	float getLambda();
	float getPrice();
	std::string getName();
	std::string getLink();
	std::string getMaterialType();
	float getPriceToLambda();
	std::string getProducer();

	float getU(unsigned char width);

	vector<ColumnAbstract<void>*>* getVectorFields();
	virtual unsigned short getFieldsNumber();
	virtual std::string getTableName();

};
