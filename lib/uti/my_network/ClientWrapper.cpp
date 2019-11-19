/*
** EPITECH PROJECT, 2019
** ClientWrapper.cpp
** File description:
**
*/

#include <iostream>
#include <string>
#include <thread>
#include "ClientWrapper.hpp"

uti::network::ClientWrapper::ClientWrapper()
        : _resolver { nullptr }, _socket { nullptr }
{}

std::string uti::network::ClientWrapper::connectToHost(const std::string &serverAddress,
                                                unsigned int port,
                                                std::string (*handleMessageReceived)(const std::string &))
{
    _resolver = new boost::asio::ip::tcp::resolver(_io_context);
    _endpoints = _resolver->resolve(serverAddress, std::to_string(port));
    _socket = new boost::asio::ip::tcp::socket(_io_context);
    boost::asio::connect(*_socket, _endpoints);
    boost::array<char, 128>     buf{};
    boost::system::error_code   error;

    size_t len = _socket->read_some(boost::asio::buffer(buf), error);
    if (error == boost::asio::error::eof)
        return ""; // Connection closed cleanly by peer.
    if (error)
        throw boost::system::system_error(error);
    std::string welcomeMessage;
    std::copy(buf.begin(), buf.begin()+ len, std::back_inserter(welcomeMessage));
    return welcomeMessage;
}

void uti::network::ClientWrapper::sendMessage(std::string message)
{

}