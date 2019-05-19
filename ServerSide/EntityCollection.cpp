#include "EntityCollection.h"



EntityCollection::EntityCollection(shared_ptr<ResultSet>& entityVector, ReadMethodInterface* methodPtr)
	:	Content<shared_ptr<ResultSet>>(entityVector),
		method(methodPtr)
{
}


EntityCollection::~EntityCollection()
{
}

ReadMethodInterface* EntityCollection::getMethod()
{
	return method;
}

