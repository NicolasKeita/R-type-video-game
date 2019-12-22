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
    uti::MyProgArgs         args(argc, argv, env, 1);

    try
    {
        uti::network::ServerUdpMultiThreadWrapper network;
        network.turnOn(std::stoi(args.getArgs().at(1)),
                       &rtype::ProtocolHandler::handleMessageReceived);
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}

