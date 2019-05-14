#include "pch.h"
#include "CreqteMethodMapper.h"


CreqteMethodMapper::CreqteMethodMapper()
	/*:	lambda(string("")),
widths(),
Tag price;
Tag type;
Tag producer;
Tag link;*/
{
}


CreqteMethodMapper::~CreqteMethodMapper()
{
}

void CreqteMethodMapper::collectData()
{
	setTag(name, "Product name:");
	setTag(lambda, "Lambda parameter:");
	setTag(price, "Price:");
	setTag(type, "Type of material (ex. wool, polistyrene etc.):");
	setTag(producer, "Producer:");
	setTag(link, "Web link:");

	setWidths();

	string allWidths;

	for (size_t i = 0; i < widthsVector.size(); i++)
		allWidths += widthsVector[i].generateBothTagsAndValue();

	widths.setValue(allWidths);
}

void CreqteMethodMapper::setTag(Tag& tag, string message)
{
	string value;
	cout << message << endl;
	cin >> value;

	tag.setValue(value);
}

void CreqteMethodMapper::setWidths()
{
	cout << "How many widths are available?" << endl;
	unsigned int widthsCount;

	do
	{
		cin.clear();
		cin.sync();
		cout << "Number has to be integral and complementary. Please correct.";
		cin >> widthsCount;
	} while (!cin);
	
	for (int i = 0; i < widthsCount; i++)
	{
		cout << "Give another width:" << endl;
		unsigned int width;

		do
		{
			cin.clear();
			cin.sync();
			
			cout << "Number has to be integral and complementary. Please correct.";
			cin >> width;
		} while (!cin);

		Tag widthTag("width");
		widthsVector.push_back(widthTag);
	}

}

string CreqteMethodMapper::generateXml()
{
	string methodBody;
	methodBody += name.generateBothTagsAndValue();
	methodBody += lambda.generateBothTagsAndValue();
	methodBody += widths.generateBothTagsAndValue();
	methodBody += price.generateBothTagsAndValue();
	methodBody += type.generateBothTagsAndValue();
	methodBody += producer.generateBothTagsAndValue();
	methodBody += link.generateBothTagsAndValue();

	string xml;

	xml += tableTag;
	xml += createMethodOpen;
		xml += methodBody;
	xml += createMethodClose;
	return xml;

}