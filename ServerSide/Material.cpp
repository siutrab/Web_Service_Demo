#include "pch.h"
#include "Material.h"


Material::Material(float lambda, float price, std::string* name)
	:	lambda(lambda),
		price(price),
		name(*name)
{	}


Material::~Material()
{	}

float Material::getU(unsigned char width) { return (lambda / width); }
float Material::getPrice(unsigned char width)
{
	
	return width;	// shitttt!!!
}

float Material::getLambda() { return lambda; }
std::string* Material::getName() { return &name; }