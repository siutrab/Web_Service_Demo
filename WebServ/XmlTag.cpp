#include "pch.h"
#include "XmlTag.h"


Tag::Tag(string tag)
	:	tagName(tag)
{	}


Tag::~Tag()
{
}

void Tag::setValue(string& value)
{
	tagValue = value;
}

string Tag::openingTag()
{
	string tag = "<" + tagName + ">";
	return tag;
}

string Tag::closeingTag()
{
	string tag = "</" + tagName + ">";
	return tag;
}

string Tag::value()
{
	return tagValue;
}

string Tag::generateBothTagsAndValue()
{
	return openingTag() + value() + closeingTag();
}