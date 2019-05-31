#include "ErrorMessage.h"

ErrorMessage::ErrorMessage(string& exception)
	:	Content<string>(exception)
{	}


ErrorMessage::~ErrorMessage()
{	}
