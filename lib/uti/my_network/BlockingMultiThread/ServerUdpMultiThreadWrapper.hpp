/*
** EPITECH PROJECT, 2019
** ServerUdpMultiThreadWrapper.hpp
** File description:
**
*/

#ifndef MY_NETWORK_LIBRARY_SERVERUDPMULTITHREADWRAPPER_HPP
#define MY_NETWORK_LIBRARY_SERVERUDPMULTITHREADWRAPPER_HPP

#include <boost/asio.hpp>
#include <memory>
#include "BlockingMultiThread/IServerUdpMultiThreadWrapper.hpp"

namespace uti::network {
    class ServerUdpMultiThreadWrapper : public IServerUdpMultiThreadWrapper {
        public:
            ServerUdpMultiThreadWrapper();

            void turnOn(unsigned int port,
                        std::string (*handleMessageReceived)(const std::string &)) override;
            void sendMessageToTheLastestClient(const std::string &message) override;

        private:
            boost::asio::io_context                         _io_context;
            std::unique_ptr<boost::asio::ip::udp::socket>   _socket;

            std::string (*_handleMessageReceived)(const std::string &);

        private:
            void _handleRequest(boost::asio::ip::udp::endpoint sender_endpoint, char *data, size_t length);
    };
}


#endif //MY_NETWORK_LIBRARY_SERVERUDPMULTITHREADWRAPPER_HPP
