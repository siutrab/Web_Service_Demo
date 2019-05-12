#include "TranslatorXml.h"


	RequestQueue* TranslatorXml::requestQueuePtr;
	NoResultQueryQueue* TranslatorXml::noResultQueryQueuePtr;
	ResultQueryQueue* TranslatorXml::resultQueryQueuePtr;
	ErrorQueue* TranslatorXml::errorQueuePtr;

	void TranslatorXml::setRequestQueuePtr(RequestQueue* pointer)
	{
		TranslatorXml::requestQueuePtr = pointer; // Settet in RequestsQueue object
		const_cast<const RequestQueue*>(TranslatorXml::requestQueuePtr);
	}

	void TranslatorXml::setNoResultQueryQueuePtr(NoResultQueryQueue* pointer)
	{
		TranslatorXml::noResultQueryQueuePtr = pointer; // Settet in QueryQueue object
		const_cast<const NoResultQueryQueue*>(TranslatorXml::noResultQueryQueuePtr);
	}
	
	void TranslatorXml::setResultQueryQueuePtr(ResultQueryQueue* pointer)
	{
		TranslatorXml::resultQueryQueuePtr = pointer; // Settet in QueryQueue object
		const_cast<const ResultQueryQueue*>(TranslatorXml::resultQueryQueuePtr);
	}

	void TranslatorXml::setErrorQueuePtr(ErrorQueue* const pointer)
	{
		TranslatorXml::errorQueuePtr = pointer; // Settet in ErrorQueue object
		const_cast<const ErrorQueue*>(TranslatorXml::errorQueuePtr);
	}


TranslatorXml::TranslatorXml()
	:	running(false),
		methodsMapper(),
		dataBaseMap(),
		queueItem(),
		request(),
		document()
{	}


TranslatorXml::~TranslatorXml()
{	}

void TranslatorXml::start()
{
	TRANSLATOR_XML_THREAD = std::thread(&TranslatorXml::run, this);
}

void TranslatorXml::stop()
{
	TRANSLATOR_XML_THREAD.join();
	running = false;
}

void TranslatorXml::run()
{
	running = true;
	while (running)
	{
		if (loadDocument()) 
			translateDocument();
	}
}

void TranslatorXml::translateDocument()
{	
	try
	{
		setTable();
		setMethod();
		chooseQueryQueue();
		prepareQuery();
	}
	catch (ExceptionInterface& exception)
	{
		errorQueuePtr->addItem(std::move(queueItem), exception);
	}
	
	queryQueuePointer->addItem(std::move(queueItem));
}

void TranslatorXml::setTable()
{
	string tableName = document->findTableName();			// WARNING!!! throws exception	
	tablePointer = &dataBaseMap.findTable(tableName);		// WARNING!!! throws exception
}

void TranslatorXml::setMethod()
{	
	string methodName = document->findMethodName();			// WARNING!!! throws exception
	methodPointer = &methodsMapper.findMethod(methodName);	// WARNING!!! throws exception
}

void TranslatorXml::chooseQueryQueue()
{
	if (methodPointer->isResulting())
		queryQueuePointer = resultQueryQueuePtr;
	else
		queryQueuePointer = noResultQueryQueuePtr;
}

void TranslatorXml::prepareQuery()
{
	unique_ptr<ContentInterface> queryPtr = methodPointer->generateQuery(*document);	// WARNING!!! throws exception

	queueItem->changeContent(queryPtr);
}

bool TranslatorXml::loadDocument()
{
	if (requestQueuePtr->isEmpty())
		return false;

	queueItem = std::move(requestQueuePtr->getItem());

	return initializeFields();
}

bool TranslatorXml::initializeFields()
{
	try
	{
		unique_ptr<ContentInterface> contentInterface(std::move(queueItem->getContentObject()));
	
		request = unique_ptr<Request>(static_cast<Request*>(contentInterface.release()));
		document.reset(new DocumentXml(*request));
		return true;
	}
	catch(...)
	{
		return false;
	}
}
