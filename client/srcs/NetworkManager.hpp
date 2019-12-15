/*
** EPITECH PROJECT, 2019
** NetworkManager.hpp
** File description:
**
*/

#ifndef MY_SFML_CINEMATIC_NETWORKMANAGER_HPP
#define MY_SFML_CINEMATIC_NETWORKMANAGER_HPP

#include <string>
#include "GameEngine.hpp"
#include "ClientUdpMultiThreadWrapper.hpp"

class NetworkManager {
    public:
        NetworkManager(const std::string & addressServer, unsigned int port);

        void handleProtocol(rtype::GameEngine &gameEngine);
        void stop();

    private:
        uti::network::ClientUdpMultiThreadWrapper _udp;
};


#endif //MY_SFML_CINEMATIC_NETWORKMANAGER_HPP
