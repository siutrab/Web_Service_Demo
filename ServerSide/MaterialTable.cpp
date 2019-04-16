#include "MaterialTable.h"

std::string IdColumn::getName()				{ return "id"; }
std::string IdColumn::getValueAsString()	{ return  std::to_string(value); }


std::string NameColumn::getName()			{ return "name"; }
std::string NameColumn::getValueAsString()	{ return value; }


std::string LambdaColumn::getName()				{ return "lambda"; }
std::string LambdaColumn::getValueAsString()	{ return std::to_string(value); }
float LambdaColumn::getValue()					{ return value; }
//void LambdaColumn::setValue(void* value)		{ this->value = *(static_cast<float*>(value)); }

//std::string PriceColumn::getName()			{ return "price"; }
//std::string PriceColumn::getValueAsString()	{ return std::to_string(value); }
//float PriceColumn::getValue()				{ return value; }
////void PriceColumn::setValue(void* value)		{ this->value = *(static_cast<float*>(value)); }
//
//
//std::string TypeOfMaterialColumn::getName()				{ return "type_of_material"; }
//std::string TypeOfMaterialColumn::getValueAsString()	{ return value; }
//std::string TypeOfMaterialColumn::getValue()			{ return value; }
////void TypeOfMaterialColumn::setValue(void* value)		{ this->value = *(static_cast<std::string*>(value)); }
//
//std::string PriceToLambdaColumn::getName()			{ return"price_to_lambda"; }
//std::string PriceToLambdaColumn::getValueAsString() { return std::to_string(value); }
//float PriceToLambdaColumn::getValue()				{ return value; }
////void PriceToLambdaColumn::setValue(void* value)		{ this->value = *(static_cast<float*>(value)); }
//
//std::string ProducerColumn::getName()			{ return "producer"; }
//std::string ProducerColumn::getValueAsString()	{ return value; }
//std::string ProducerColumn::getValue()			{ return value; }
////void ProducerColumn::setValue(void* value)		{ this->value = *(static_cast<std::string*>(value)); }
//
//std::string LinkColumn::getName()			{ return "link"; }
//std::string LinkColumn::getValueAsString() { return value; }
//std::string LinkColumn::getValue() { return value; }
////void LinkColumn::setValue(void* value) { this->value = *(static_cast<std::string*>(value)); }

MaterialTable::MaterialTable()
	:	idColumn(),
		nameColumn(),
		lambdaColumn(),
		//priceColumn(),
		//typeColumn(),
		//priceLambdaColumn(),
		//producerColumn(),
		//linkColumn(),
		// vector initialization
		Fields(
		{
			&idColumn,
			&nameColumn,
			&lambdaColumn,
			//&priceColumn,
			//&typeColumn,
			//&priceLambdaColumn,
			//&producerColumn,
			//&linkColumn
		})
{
	idColumn.setValue(7);
	std::cout << idColumn.getValue(); 
}

MaterialTable::~MaterialTable()
{
}

std::vector<ColumnAbstract<void>>* MaterialTable::getFields() { return &Fields; }