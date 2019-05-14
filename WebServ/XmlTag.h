#pragma once
#include <string>

using std::string;
class Tag
{
	
	string tagName;
	string tagValue;
public:
	Tag(string tag);
	~Tag();
	void setValue(string& value);
	string openingTag();
	string closeingTag();
	string value();
	string generateBothTagsAndValue();
};


