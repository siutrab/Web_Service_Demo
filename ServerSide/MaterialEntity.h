#pragma once
#include <vector>
#include <memory>
#include "MaterialEntity.h"
#include "MappingInterface.h"

using std::string;
using std::vector;
using std::shared_ptr;

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
};

