#pragma once
#include "Content.h"
#include "EntityInterface.h"
#include <vector>

using std::vector;

class EntityInterface;

class EntityCollection
	:	public Content<vector<unique_ptr<EntityInterface>>>
{
public:
	EntityCollection(vector<unique_ptr<EntityInterface>>& entityVector);
	~EntityCollection();
};

