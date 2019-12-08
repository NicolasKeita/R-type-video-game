/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
**
*/

#include <iostream>
#include <boost/algorithm/string/predicate.hpp>
#include "ServerUdpMultiThreadWrapper.hpp"

std::string handleMessageReceived(const std::string &messageReceived)
{
    std::cerr << "Message receive: DEBUT" << messageReceived << "FIN" << std::endl;

    static int i = 1;
    try {
        if (boost::starts_with(messageReceived, "IDREQUEST")) {
            return "ID " + std::to_string(i++);
        }
    } catch (std::invalid_argument &e) {
        std::cerr << "[Rtype server] wrong arg to stoi" << std::endl;
    }
    return messageReceived;
}

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    (void)env;

    try
    {
        uti::network::ServerUdpMultiThreadWrapper network;
        network.turnOn(42424, &handleMessageReceived);
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}

