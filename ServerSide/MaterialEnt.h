#pragma once
#include <vector>
#include <memory>
#include "TableAbstract.h"

using std::string;
using std::vector;
using std::shared_ptr;

class MaterialEnt
	: public EntityInterface
{
	

public:
	MaterialEnt(unsigned int	id,
				float			lambda, 
				float			price, 
				float			priceLambda, 
				std::string&	name, 
				std::string&	link, 
				std::string&	materialType, 
				std::string&	producer);
	~MaterialEnt();
};

