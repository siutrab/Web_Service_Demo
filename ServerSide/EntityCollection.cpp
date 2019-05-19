#include "EntityCollection.h"



EntityCollection::EntityCollection(vector<unique_ptr<EntityInterface>>& entityVector)
	: Content<vector<unique_ptr<EntityInterface>>>(entityVector)
{
}


EntityCollection::~EntityCollection()
{
}
