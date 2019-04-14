#pragma once
#include <string>
#include "EntityAbstract.h"
#include "boost/any.hpp"
#include <vector>
#include "MaterialTable.h"


class MaterialEntity 
	: public	EntityAbstract
{
	MaterialTable* materialTable;
public:
	
	MaterialEntity(unsigned int id, float lambda, float price, std::string& name, std::string& link, std::string& materialType, std::string& producer);
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

	virtual std::pair<std::string, std::string>* getPair(unsigned int index);
	//virtual std::vector<ColumnAbstract*>* getVectorFields();
	virtual unsigned short getFieldsNumber();
	virtual std::string getTableName();
};
