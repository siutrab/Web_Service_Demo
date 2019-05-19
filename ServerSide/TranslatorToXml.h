#pragma once
#include "DocumentXml.h"
#include <memory>

using std::unique_ptr;

class TranslatorToXml
{
	unique_ptr<DocumentXml> document;
public:
	TranslatorToXml();
	~TranslatorToXml();
};

