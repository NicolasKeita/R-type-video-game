/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
**
*/

#include <iostream>
#include "ServerUdpMultiThreadWrapper.hpp"
#include "MyProgArgs.hpp"
#include "ProtocolHandler.hpp"

int main(int argc, char **argv, char **env)
{
    uti::MyProgArgs         args(argc, argv, env, 0);

    try
    {
        int port;
        if (args.getSize() > 1)
            port = std::stoi(args.getArgs().at(1));
        else
            port = 42424;
        uti::network::ServerUdpMultiThreadWrapper network;
        network.turnOn(port, &rtype::ProtocolHandler::handleMessageReceived);
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}

