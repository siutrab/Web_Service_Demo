#include "pch.h"
#include "QueryGenerator.h"


QueryGenerator::QueryGenerator()
{
}


QueryGenerator::~QueryGenerator()
{
}


unique_ptr<SQLString> QueryGenerator::selectAll()
{ 
	string query = "SELECT * FROM `materials`;";
	return std::make_unique<SQLString>(query.c_str());
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
	std::cout << Query << std::endl << std::endl;
	
	auto querySql = std::make_unique<SQLString>(Query.c_str());
	return std::move(querySql);

}
