#pragma once
#include "SFML/Network/TcpListener.hpp"

class Listener
{
	sf::TcpListener listener;
public:
	Listener();
	~Listener();
};

