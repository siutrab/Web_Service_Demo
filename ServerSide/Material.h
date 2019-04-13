#pragma once
#include <string>

class Material
{
		std::string name;
		const float lambda;
		const float price;
		
public:
	Material(float lambda, float price, std::string* name);
	~Material();
	float getLambda();
	float getU(unsigned char width);
	float getPrice(unsigned char width);
	std::string* getName();
};
