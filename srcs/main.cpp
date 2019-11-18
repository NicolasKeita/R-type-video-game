/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
**
*/

#include <iostream>

int main(int argc, char **argv, char **env)
{
    std::cout << "Hello world !" << std::endl;
    return 0;
}

/*
#include <iostream>
#include "ServerWrapper.hpp"

std::string handleMessageReceived(const std::string &messageReceived)
{
    return "";
}

int main(int argc, char **argv, char **env)
{
    std::cerr << "[DEBUG] begin" << std::endl;
    try
    {
        // Blocking
        uti::network::ServerWrapper server(42424,
                                           &handleMessageReceived,
                                           "WELCOME, you have successfully connected");
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

*/