/*
** EPITECH PROJECT, 2019
** NetworkManager.hpp
** File description:
**
*/

#ifndef MY_SFML_CINEMATIC_NETWORKMANAGER_HPP
#define MY_SFML_CINEMATIC_NETWORKMANAGER_HPP

#include <string>
#include <SFML/System/Clock.hpp>
#include "GameEngine.hpp"
#include "ClientUdpMultiThreadWrapper.hpp"

class NetworkManager {
    public:
        NetworkManager(const std::string & addressServer, unsigned int port);

        void        handleProtocol(rtype::GameEngine &gameEngine);
        std::string protocolDecideWhichMessageToSend(const rtype::GameEngine &gameEngine);
        int         protocolHandleReceivedMessages(const std::string &reply,
                                               rtype::GameEngine &gameEngine);
        void        stop();

    private:
        uti::network::ClientUdpMultiThreadWrapper   _udp;
        sf::Clock                                   _clock; // TODO : remove dependancy to SFML
};


#endif //MY_SFML_CINEMATIC_NETWORKMANAGER_HPP
