#include "ResponseTranslatorXml.h"



ResponseTranslatorXml::ResponseTranslatorXml(ErrorHandler* errorQueue, Queue* responseQueue, Queue* entityQueue)
	:	errorHandler(errorQueue),
		responseQueue(responseQueue),
		sqlResultQueue(entityQueue),
		running(false)
{	}


ResponseTranslatorXml::~ResponseTranslatorXml()
{	}


void ResponseTranslatorXml::start()
{
	running = true;
	TRANSLATOR_TO_XML_THREAD = thread(&ResponseTranslatorXml::run, this);
}

void ResponseTranslatorXml::stop()
{
	running = false;
	if(TRANSLATOR_TO_XML_THREAD.joinable())
		TRANSLATOR_TO_XML_THREAD.join();
}


void ResponseTranslatorXml::run()
{
	while (running)
	{
		if (takeQueueItem())
		{
			auto xmlResponse = generateXmlDocument();
			pushResponseOnQueue(std::move(xmlResponse));
		}
	}
}


bool ResponseTranslatorXml::takeQueueItem()
{
	if (sqlResultQueue->isEmpty())
		return false;
	else
	{
		setQueueItem();
		setContent();
		setMethod();
		setResultSet();
		return true;
	}
	
}

void ResponseTranslatorXml::setQueueItem()
{
	queueItem.reset(sqlResultQueue->getItem().release());
}

void ResponseTranslatorXml::setMethod()
{
	method = content->getMethod();
}

void ResponseTranslatorXml::setContent()
{
	ContentInterface* queueItemContent = queueItem->getContentObject().release();
	ResultSetContent* resultSetContent = dynamic_cast<ResultSetContent*>(queueItemContent);
	content.reset(resultSetContent);
}

void ResponseTranslatorXml::setResultSet()
{
	void* sqlResultSet = content->getContent();
	shared_ptr<ResultSet>* casetedResultSet = static_cast<shared_ptr<ResultSet>*>(sqlResultSet);

	resultSet.swap(*casetedResultSet);
}

unique_ptr<string> ResponseTranslatorXml::generateXmlDocument()
{
	unsigned int requestId = queueItem->getId();
	vector<unique_ptr<EntityInterface>> entitiesVector = method->generateEntities(resultSet);
	document.reset(new DocumentXml(entitiesVector, requestId));

	auto xmlDocument = document->generateXml();
	return std::move(xmlDocument);

}

void ResponseTranslatorXml::pushResponseOnQueue(unique_ptr<string> xmlDocument)
{
	unique_ptr<ContentInterface> newContent = std::make_unique<Response>(*xmlDocument);

	queueItem->changeContent(newContent);
	responseQueue->addItem(std::move(queueItem));
}

