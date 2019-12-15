/*
** EPITECH PROJECT, 2019
** ClientUdpMultiThreadWrapper.cpp
** File description:
**
*/


#include "ClientUdpMultiThreadWrapper.hpp"

using boost::asio::ip::udp;

uti::network::ClientUdpMultiThreadWrapper::ClientUdpMultiThreadWrapper()
        : _socket { _io_context, udp::endpoint(udp::v4(), 0) },
          _resolver { _io_context },
          _serverAddress { "-1" },
          _port { 0 },
          _serverSet { false }
{}

void uti::network::ClientUdpMultiThreadWrapper::setServer(const std::string &serverAddress,
                                                          size_t port)
{
    _serverAddress = serverAddress;
    _port = port;
    /*
    _socket = std::make_unique<udp::socket>(_io_context,
                                            udp::endpoint(udp::v4(), 0));
                                            */
//    _endpoints = std::make_unique<udp::resolver::results_type
    _endpoints = _resolver.resolve(udp::v4(),
                                   _serverAddress,
                                   std::to_string(_port));
    _serverSet = true;
}

void uti::network::ClientUdpMultiThreadWrapper::sendMessage(const std::string & message)
{
    size_t request_length = message.size();
    _socket.send_to(boost::asio::buffer(message,
                                        request_length),
                    *_endpoints.begin());
}

//Blocking
std::string uti::network::ClientUdpMultiThreadWrapper::getReply()
{
    char reply[1024];
    udp::endpoint sender_endpoint;
    size_t reply_length = _socket.receive_from(
            boost::asio::buffer(reply, 1024),
            sender_endpoint); // blocking function
    //sender_endpoint is now equal to the server
    return std::string(reply, reply_length);
}

void uti::network::ClientUdpMultiThreadWrapper::stop()
{
    _socket.shutdown(boost::asio::ip::udp::socket::shutdown_both);
//    this->_socket.close();
}