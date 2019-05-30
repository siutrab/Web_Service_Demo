#include "ErrorHandler.h"


ErrorHandler::ErrorHandler(Queue* responseQueue)
	:	errorLogger(),
		errorTranslator(),
		responseQueue(responseQueue)
{	}


ErrorHandler::~ErrorHandler()
{	}


void ErrorHandler::createError(unique_ptr<QueueItem> item, ExceptionInterface& exception)
{
	auto contentObject = item->getContentObject();
	unsigned int requestId = item->getId();
	
	errorLogger.logError(exception);
	auto error = errorTranslator.generateErrorXml(exception, requestId);

	unique_ptr<ContentInterface> newContent = std::make_unique<Response>(*error);
	item->changeContent(newContent);
	
	responseQueue->addItem(std::move(item));
}
