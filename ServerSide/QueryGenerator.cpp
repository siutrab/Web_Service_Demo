#include "pch.h"
#include "QueryGenerator.h"


// !!! TO DO !!!
unique_ptr<SQLString> QueryGenerator::selectByIndex(EntityInterface &entity, unsigned int index) { return unique_ptr<SQLString>(new SQLString()); }
unique_ptr<SQLString> QueryGenerator::selectAll(EntityInterface &entity){ return unique_ptr<SQLString>(new SQLString()); }
unique_ptr<SQLString> QueryGenerator::selectOrderBy(EntityInterface &entity, unsigned short columnIndex){ return unique_ptr<SQLString>(new SQLString()); }


QueryGenerator::QueryGenerator()
{
}


QueryGenerator::~QueryGenerator()
{
}

unique_ptr<string> QueryGenerator::separateWithSymbols(vector<string>& collection, string firstSymbol, string separatingSymbol, string endingSymbol)
{
	auto finalString = std::make_unique<string>(firstSymbol);
	size_t lastIndex = collection.size() - 1;
	for (size_t i = 0; i < lastIndex; i++)	// lastIndex - 1, because the las iteration is different (contains endingSymbol, not separatingSymbol)
	{
		*finalString += collection[i];
		*finalString += separatingSymbol;
	}
	*finalString += collection[lastIndex];
	*finalString += endingSymbol;

	return std::move(finalString);
}


unique_ptr<SQLString> QueryGenerator::insert(vector<unique_ptr<EntityInterface>>& entityCollection)
{
	EntityInterface& firstEntity = *entityCollection[0];
	auto fieldsVector = firstEntity.getFieldsVector();
	vector<string> fieldNames(fieldsVector->size() - 1);	// size - 1, because first column is autoincremented so its not taking a part in query

	for (size_t i = 1; i < fieldsVector->size(); i++)
	{
		auto columnNamePtr = (*fieldsVector)[i]->getColumnName();
		fieldNames[i - 1] = *columnNamePtr;
	}

	auto queryFirstPart = separateWithSymbols(fieldNames, "(`", "`,`", "`)");

	
	vector<string> querySecondPartVector;
	size_t lastEntityIndex = entityCollection.size();
	for (size_t i = 0; i < lastEntityIndex; i++)
	{
		fieldsVector = entityCollection[i]->getFieldsVector();

		size_t lastFieldIndex = fieldsVector->size();
		for (size_t j = 1; j < lastFieldIndex; j++)
		{
			auto columnValuePtr = (*fieldsVector)[j]->getValueAsString();
			fieldNames[j - 1] = *columnValuePtr;
		}
		querySecondPartVector.push_back(*separateWithSymbols(fieldNames, "(\"", "\",\"", "\")"));
	}
	
	auto querySecondPart = separateWithSymbols(querySecondPartVector, "", ",", "");

	string Query = "INSERT INTO `" + firstEntity.getTableName() + "`" + *queryFirstPart + "VALUES" + *querySecondPart;
	std::cout << Query;
	
	auto querySql = std::make_unique<SQLString>(Query.c_str());
	return std::move(querySql);

}

//unique_ptr<SQLString> QueryGenerator::insert(vector<unique_ptr<EntityInterface>>& entityCollection)
//{
//	EntityInterface& firstEntity = *entityCollection[0];
//	unique_ptr<string>queryFirstPart = std::move(entityFieldsToQueryPart(firstEntity));
//	
//	auto querySecondPart = std::make_unique<string>();
//
//	size_t entityCollectionLastIndex = entityCollection.size() - 1;
//
//	for (size_t i = 0; i < entityCollectionLastIndex; i++)
//	{
//		auto queuePart = std::move(entityValuesToQueryPart(*(entityCollection)[i]));
//		*querySecondPart += *queuePart + ",";
//	}
//	*querySecondPart += *(entityValuesToQueryPart(*(entityCollection)[entityCollectionLastIndex]));
//
//
//	string Query = "INSERT INTO `" + firstEntity.getTableName() + "`" + *queryFirstPart + "VALUES" + *querySecondPart;
//	std::cout << Query;
//	
//	auto querySql = std::make_unique<SQLString>(Query.c_str());
//	return std::move(querySql);
//
//}
//
//unique_ptr<string> QueryGenerator::entityValuesToQueryPart(EntityInterface& entity)
//{
//	vector<unique_ptr<FieldInterface>>* Fields = entity.getFieldsVector();
//	size_t lastIndex = Fields->size() - 1;
//	unique_ptr<string>queryPart(new string("("));
//
//	for (size_t i = 1; i < lastIndex; i++)		// starts from index 1 because index 0 ("id") is autoincremented primary key in db
//	{
//		*queryPart += "\"" + *((*Fields)[i]->getValueAsString()) + "\",";
//	}
//	*queryPart += "\"" + *((*Fields)[lastIndex]->getValueAsString()) + "\")";
//
//	return std::move(queryPart);
//}
//
//unique_ptr<string> QueryGenerator::entityFieldsToQueryPart(EntityInterface& entity)
//{
//	vector<unique_ptr<FieldInterface>>* Fields = entity.getFieldsVector();
//	size_t lastIndex = Fields->size() - 1;
//	unique_ptr<string>queryPart(new string("("));
//
//	for (size_t i = 1; i < lastIndex; i++)		// starts from index 1 because index 0 ("id") is autoincremented primary key in db
//	{
//		*queryPart += "`" + *((*Fields)[i]->getColumnName()) + "`,";
//	}
//	*queryPart += "`" + *((*Fields)[lastIndex]->getColumnName()) + "`)";
//
//	return std::move(queryPart);
//}
