#pragma once
#include "DocumentXml.h"
#include "TableInterface.h"
#include "MethodInterface.h"
#include "MethodsMapper.h"

class TranslatorXml
{
	DataBaseMap dataBaseMap;
	MethodsMapper methodsMapper;
		DocumentXml* document;
		shared_ptr<TableInterface> tablePointer;
		shared_ptr<MethodInterface> methodPointer;

		

	void run();
	void loadDocument();
	bool translateDocument();

	void findTable();
	void findMethod();
	bool findParameters();

public:
	TranslatorXml();
	~TranslatorXml();
	void start();
	void stop();


};

