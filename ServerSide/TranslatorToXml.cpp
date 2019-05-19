#include "TranslatorToXml.h"



TranslatorToXml::TranslatorToXml(ErrorQueue* errorQueue, Queue* responseQueue, Queue* entityQueue)
	:	errorQueue(errorQueue),
		responseQueue(responseQueue),
		entityQueue(entityQueue),
		running(false)
{
}


TranslatorToXml::~TranslatorToXml()
{
}

void TranslatorToXml::run()
{
	while (running)
	{
		if (takeQueueItem())
		{
			vector<unique_ptr<EntityInterface>> entitiesVector = method->generateEntities(resultSet);
			document.reset(new DocumentXml(entitiesVector));

			auto xmlResponse = document->generateXml();
			unique_ptr<ContentInterface> newContent = std::make_unique<Response>(*xmlResponse);

			queueItem->changeContent(newContent);
			responseQueue->addItem(std::move(queueItem));
		}
	}
}

bool TranslatorToXml::takeQueueItem()
{
	if (entityQueue->isEmpty())
	{
		return false;
	}
	else
	{
		queueItem.reset(entityQueue->getItem().release());

		ContentInterface* queueItemContent = queueItem->getContentObject().release();
		EntityCollection* entityCollection = dynamic_cast<EntityCollection*>(queueItemContent);

		content.reset(entityCollection);

		method = content->getMethod();

		void* sqlResultSet = content->getContent();
		shared_ptr<ResultSet>* casetedResultSet = static_cast<shared_ptr<ResultSet>*>(sqlResultSet);
		//auto castedResultSet = std::static_pointer_cast<ResultSet>(sqlResultSet);
		resultSet.swap(*casetedResultSet);
		return true;
	}
	
}

void TranslatorToXml::start()
{
	running = true;
	TRANSLATOR_TO_XML_THREAD = thread(&TranslatorToXml::run, this);
	
}

void TranslatorToXml::stop()
{
	running = false;
	if(TRANSLATOR_TO_XML_THREAD.joinable())
		TRANSLATOR_TO_XML_THREAD.join();
}