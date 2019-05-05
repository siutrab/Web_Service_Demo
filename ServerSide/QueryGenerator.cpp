#include "QueryGenerator.h"


// !!! TO DO !!!
unique_ptr<SQLString> QueryGenerator::selectByIndex(EntityInterface &entity, unsigned int index) { return unique_ptr<SQLString>(new SQLString()); }
unique_ptr<SQLString> QueryGenerator::selectAll(EntityInterface &entity){ return unique_ptr<SQLString>(new SQLString()); }
unique_ptr<SQLString> QueryGenerator::selectOrderBy(EntityInterface &entity, unsigned short columnIndex){ return unique_ptr<SQLString>(new SQLString()); }


QueryGenerator::QueryGenerator(/*DatabaseHandler* pointer*/)
	//:	databaseHandler(pointer)
{
}


QueryGenerator::~QueryGenerator()
{
}


unique_ptr<SQLString> QueryGenerator::insert(vector<unique_ptr<EntityInterface>>& entityCollection)
{
	EntityInterface& firstEntity = *entityCollection[0];
	unique_ptr<string>queryFirstPart = std::move(entityFieldsToQueryPart(firstEntity));
	
	auto querySecondPart = std::make_unique<string>();

	size_t entityCollectionLastIndex = entityCollection.size() - 1;

	for (size_t i = 0; i < entityCollectionLastIndex; i++)
	{
		auto queuePart = std::move(entityValuesToQueryPart(*(entityCollection)[i]));
		*querySecondPart += *queuePart + ",";
	}
	*querySecondPart += *(entityValuesToQueryPart(*(entityCollection)[entityCollectionLastIndex]));


	string Query = "INSERT INTO `" + firstEntity.getTableName() + "`" + *queryFirstPart + "VALUES" + *querySecondPart;
	std::cout << Query;
	
	auto querySql = std::make_unique<SQLString>(Query.c_str());
	return std::move(querySql);

}

unique_ptr<string> QueryGenerator::entityValuesToQueryPart(EntityInterface& entity)
{
	vector<unique_ptr<FieldInterface>>* Fields = entity.getFieldsVector();
	size_t lastIndex = Fields->size() - 1;
	unique_ptr<string>queryPart(new string("("));

	for (size_t i = 1; i < lastIndex; i++)		// starts from index 1 because index 0 ("id") is autoincremented primary key in db
	{
		*queryPart += "\"" + *((*Fields)[i]->getValueAsString()) + "\",";
	}
	*queryPart += "\"" + *((*Fields)[lastIndex]->getValueAsString()) + "\")";

	return std::move(queryPart);
}

unique_ptr<string> QueryGenerator::entityFieldsToQueryPart(EntityInterface& entity)
{
	vector<unique_ptr<FieldInterface>>* Fields = entity.getFieldsVector();
	size_t lastIndex = Fields->size() - 1;
	unique_ptr<string>queryPart(new string("("));

	for (size_t i = 1; i < lastIndex; i++)		// starts from index 1 because index 0 ("id") is autoincremented primary key in db
	{
		*queryPart += "`" + *((*Fields)[i]->getColumnName()) + "`,";
	}
	*queryPart += "`" + *((*Fields)[lastIndex]->getColumnName()) + "`)";

	return std::move(queryPart);
}
