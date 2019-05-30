#include "pch.h"
#include "ResponseTranslator.h"

const string ResponseTranslator::successMessageFirstPart =
"<?xml version=\"1.0\"?>\
<soap:Envelope>\
<soap:Body>\
<response id=\"";

const string ResponseTranslator::successMessageSecondPart = "\" \
result=\"success\"/>\
</soap:Body>\
</soap:Envelope>";

ResponseTranslator::ResponseTranslator()
{
}


ResponseTranslator::~ResponseTranslator()
{
}

unique_ptr<Response> ResponseTranslator::generateSuccessMessage(QueueItem& queueItem)
{
	string message = ResponseTranslator::successMessageFirstPart;
	if (queueItem.idIsKnown())
		message += std::to_string(queueItem.getId());
	else
		message += "unknown";


	message += ResponseTranslator::successMessageSecondPart;

	auto response = std::make_unique<Response>(message);
	return std::move(response);
}