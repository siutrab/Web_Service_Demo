#include "pch.h"
#include "ConnectionHandler.h"


ConnectionHandler::ConnectionHandler()
	:	socket(),
		listener()
{
	listener.accept(socket);
	listener.setBlocking(false);
	listener.listen(socket.getLocalPort());
}


ConnectionHandler::~ConnectionHandler()
{
}
