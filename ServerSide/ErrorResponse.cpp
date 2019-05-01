#include "ErrorResponse.h"

ErrorResponse::ErrorResponse(string& exception)
	:	Content<string>(exception)
{

}


ErrorResponse::~ErrorResponse()
{
}
