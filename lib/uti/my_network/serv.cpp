/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
**
*/

#include <iostream>
#include "ServerWrapper.hpp"

std::string handleMessageReceived(const std::string &messageReceived)
{
	return "";
}

int main()
{
    std::cerr << "[DEBUG] begin" << std::endl;
    try
    {
        // Blocking
        
	uti::network::ServerWrapper server;

        server.turnOn(42424,
			&handleMessageReceived,
			"WELCOME, you have successfully connected");
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

