#include "pch.h"
#include "RequestsQueueXML.h"

RequestsQueueXml::RequestsQueueXml()

{
	Client::setRequestQueuePtr(this);
	TranslatorXML::setRequestQueuePointer(this);
}
