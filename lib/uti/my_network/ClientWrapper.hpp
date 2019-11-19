/*
** EPITECH PROJECT, 2019
** ClientWrapper.hpp
** File description:
**
*/

#ifndef R_TYPE_VIDEO_GAME_CLIENTWRAPPER_HPP
#define R_TYPE_VIDEO_GAME_CLIENTWRAPPER_HPP

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "IClientWrapper.hpp"

namespace uti::network {
    class ClientWrapper : public IClientWrapper {
        public:
            ClientWrapper();
            std::string connectToHost(const std::string &serverAddress,
                                      unsigned int port,
                                      std::string (*handleMessageReceived)(const std::string &)) override;
            void sendMessage(std::string message) override;

        private:
            boost::asio::io_context                       _io_context;
            boost::asio::ip::tcp::resolver *              _resolver;
            boost::asio::ip::tcp::resolver::results_type  _endpoints;
            boost::asio::ip::tcp::socket *                _socket;
    };
}


#endif //R_TYPE_VIDEO_GAME_CLIENTWRAPPER_HPP
