#pragma once
#include <string>

using std::string;

class ExceptionInterface
{
protected:
	string value;
	unsigned int id;
public:
	string& getValue()
	{
		return value;
	}
};

struct ServerExceptions
{

	struct QueryMappingExceptions
	{
		struct WrongTableName
			: public ExceptionInterface
		{
			WrongTableName() { value = "Wrong table name."; }
		};

		struct WrongArgument
			: public ExceptionInterface
		{
			WrongArgument() { value = "Can't call function. Wrong arguments have been given."; }
		};

		struct WrongMethodName
			: public ExceptionInterface
		{
			WrongMethodName() { value = "Wrong method name."; }
		};

		struct NodeNotFound
			: public ExceptionInterface
		{
			NodeNotFound() { value = "Node was not found."; }
		};
	};

	struct ReceivingPacketExceptions
	{
		struct CantUnpackPacket
			: public ExceptionInterface
		{
			CantUnpackPacket() { value = "Server cannot unpack message."; }
		};

	};
};
