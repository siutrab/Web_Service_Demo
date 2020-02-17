#include "pch.h"
#include "Server.h"
#include <iostream>
#include <cstdlib>
#include <string>


using std::unique_ptr;
using std::string;
using std::cout;
using std::cin;
using std::endl;

void eraseWhitespaces(string& str);
void eraseSpaces(string& str);
void eraseWhitespacesExceptSpace(string& str);

int main()
{
	Server server(54000);
	server.start();
	cout << "Server runs. Press any key to stop." << endl;
	std::cin.get();
	server.stop();

	std::exit(0);
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

