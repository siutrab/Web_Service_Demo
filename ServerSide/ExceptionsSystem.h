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

		struct IDundefined
			: public ExceptionInterface
		{
			IDundefined() { value = "Server cannot read a request ID number."; }
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

		struct CannotConvertXml
			: public ExceptionInterface
		{
			CannotConvertXml() { value = "Server is unable to convert xml file."; }
		};

		struct InvalidDocument
			: public ExceptionInterface
		{
			InvalidDocument() { value = "XML file is not valid."; }
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
