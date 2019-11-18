/*
** EPITECH PROJECT, 2019
** INetworkCLientWrapper.hpp
** File description:
**
*/

#ifndef INETWORKSERVERWRAPPER_HPP
#define INETWORKSERVERWRAPPER_HPP

#include <string>

namespace uti::network {
    class IServerWrapper {
            /*
             * Blocking server
             */
        public:
            virtual void turnOn(unsigned int port,
                                std::string (*handleMessageReceived)(const std::string &),
                                const std::string &welcomeMessage) = 0;
            virtual void sendMessageToTheLastestClient(const std::string &message) = 0;
    };
}

#endif //INETWORKSERVERWRAPPER_HPP
