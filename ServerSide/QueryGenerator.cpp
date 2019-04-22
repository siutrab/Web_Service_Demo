#include "QueryGenerator.h"



QueryGenerator::QueryGenerator(DatabaseHandler* pointer)
	:	databaseHandler(pointer)
{
}


QueryGenerator::~QueryGenerator()
{
}


unique_ptr<SQLString> QueryGenerator::insert(vector<EntityInterface*> &entityCollection)
{
	//vector<unique_ptr<FieldInterface>>* Fields = entity.getFieldsVector();
	//string columnsNames;
	//string columnsValues;

	//size_t lastIndex = Fields->size() - 1;

	//for (size_t i = 1; i < lastIndex; i++)		// starts from index 1 because index 0 ("id") is autoincremented primary key in db
	//{
	//	columnsValues += "\"" + *((*Fields)[i]->getValueAsString()) + "\",";
	//	columnsNames += "`" + *((*Fields)[i]->getColumnName()) + "`,";
	//}
	//columnsValues += "\"" + *((*Fields)[lastIndex]->getValueAsString()) + "\"";
	//columnsNames += "`" + *((*Fields)[lastIndex]->getColumnName()) + "`";

	//string Query = "INSERT INTO `" + entity.getTableName() + "`(" + columnsNames + ")VALUES(" + columnsValues + ")";
	//std::cout << Query << std::endl;
	//return unique_ptr<SQLString>(new sql::SQLString(Query.c_str()));

	EntityInterface* firstEntity = entityCollection[0];
	unique_ptr<string>queryFirstPart = entityFieldsToQueryPart(*firstEntity);
	
	string querySecondPart;

	size_t entityCollectionLastIndex = entityCollection.size() - 1;

	for (size_t i = 0; i < entityCollectionLastIndex; i++)
	{
		querySecondPart += *(entityValuesToQueryPart(*(entityCollection)[i])) + ",";
	}
	querySecondPart += *(entityValuesToQueryPart(*(entityCollection)[entityCollectionLastIndex]));

	string Query = "INSERT INTO `" + firstEntity->getTableName() +"`" + *queryFirstPart + "VALUES" + querySecondPart;
	std::cout << Query;
	return unique_ptr<SQLString>(new sql::SQLString(Query.c_str()));

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

	return queryPart;
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

	return queryPart;
}