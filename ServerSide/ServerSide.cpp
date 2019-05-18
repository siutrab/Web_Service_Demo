#include "pch.h"
#include "Server.h"
#include <iostream>


using std::unique_ptr;
using std::string;

void eraseWhitespaces(string& str);
void eraseSpaces(string& str);
void eraseWhitespacesExceptSpace(string& str);

int main()
{
	Server server(54000);
	server.start();
	
	std::cin.get();
}

	
void eraseWhitespaces(string& str)
{
	string newStr;
	for (size_t i = 0; i < str.size(); i++)
	{
		char c = str[i];
		if (c != ' ' && c != '\n' && c != '\r' && c != '\t' && c != '\v' && c != '\f')
			newStr += c;
	}
	str = newStr;
}

void eraseSpaces(string& str)
{
	string newStr;
	for (size_t i = 0; i < str.size(); i++)
	{
		char c = str[i];
		if (c != ' ')
			newStr += c;
	}
	str = newStr;
}

void eraseWhitespacesExceptSpace(string& str)
{
	string newStr;
	for (size_t i = 0; i < str.size(); i++)
	{
		char c = str[i];
		if (c != '\n' && c != '\r' && c != '\t' && c != '\v' && c != '\f')
			newStr += c;
	}
	str = newStr;
}

