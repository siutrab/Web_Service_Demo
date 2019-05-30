#include "ReadMethod.h"



ReadMethodMaterials::ReadMethodMaterials(QueryGenerator* queryGenerator)
	:	queryGenerator(queryGenerator)
{
}


ReadMethodMaterials::~ReadMethodMaterials()
{	}


vector<unique_ptr<EntityInterface>> ReadMethodMaterials::generateEntities(shared_ptr<ResultSet> resultSet)
{
	vector<unique_ptr<EntityInterface>> entitiesVector;
	try
	{
		while (resultSet->next())
		{
			unsigned int	id = resultSet->getUInt("id");
			float			lambda = static_cast<float>(resultSet->getDouble("lambda"));
			float			price = static_cast<float>(resultSet->getDouble("price"));
			float			priceLambda = static_cast<float>(resultSet->getDouble("price_to_lambda"));
			unsigned short	width = static_cast<unsigned short>(resultSet->getInt("width"));
			SQLString			nameSql = resultSet->getString("name");
			SQLString			linkSql = resultSet->getString("link");
			SQLString			materialTypeSql = resultSet->getString("type_of_material");
			SQLString			producerSql = resultSet->getString("producer");

			string name(nameSql.c_str());
			string link(linkSql.c_str());
			string materialType(materialTypeSql.c_str());
			string producer(producerSql.c_str());

			auto entity = std::make_unique<MaterialEntity>(
				id,
				lambda,
				price,
				priceLambda,
				width,
				name,
				link,
				materialType,
				producer);

			entitiesVector.push_back(std::move(entity));
		}
	}
	catch(...)
	{
		throw ServerExceptions::DatabaseExceptions::CannotReadResult();
	}
	return entitiesVector;
}


unique_ptr<Query> ReadMethodMaterials::generateQuery(DocumentXml& document)
{
	auto queryString = queryGenerator->selectAll();
	auto query = std::make_unique<ResultingQuery>(*queryString, this);

	return std::move(query);
}


unique_ptr<string> ReadMethodMaterials::getMethodName()
{
	return std::make_unique<string>("read");
}


bool ReadMethodMaterials::isResulting()
{
	return true;
}