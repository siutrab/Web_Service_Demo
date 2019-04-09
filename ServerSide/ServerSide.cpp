#include "pch.h"
#include <iostream>
#include "Server.h"

#define __FD_SETSIZE    1024


int main()
{
	Server server(54000);
	std::cin.get();
}
