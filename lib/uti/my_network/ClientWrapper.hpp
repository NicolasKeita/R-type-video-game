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
#include <string>
#include "IClientWrapper.hpp"

namespace uti::network {
    class ClientWrapper : public IClientWrapper {
        public:
            ClientWrapper();
            void connectToHost(const std::string &serverAddress,
                               unsigned int port,
                               std::string (*handleMessageReceived)(const std::string &)) override;
            void sendMessage(const std::string &message) override;

        private:
            void _handleRead(const boost::system::error_code & e,
                             std::size_t bytesTransferred);

        public:
            boost::asio::io_context                       _io_context;
        private:
            boost::asio::ip::tcp::resolver *              _resolver;
            boost::asio::ip::tcp::resolver::results_type  _endpoints;
            boost::asio::ip::tcp::socket *                _socket;
            boost::array<char, 128>                       _buf;
            std::string (*_handleMessageReceived)(const std::string &);
    };
}


#endif //R_TYPE_VIDEO_GAME_CLIENTWRAPPER_HPP
