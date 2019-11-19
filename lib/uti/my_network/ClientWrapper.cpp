/*
** EPITECH PROJECT, 2019
** ClientWrapper.cpp
** File description:
**
*/

#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/noncopyable.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/format.hpp>
#include <thread>
#include "ClientWrapper.hpp"

uti::network::ClientWrapper::ClientWrapper()
        : _resolver { nullptr }, _socket { nullptr }, _buf {}, _handleMessageReceived { nullptr }
{}

void uti::network::ClientWrapper::connectToHost(const std::string &serverAddress,
                                                unsigned int port,
                                                std::string (*handleMessageReceived)(const std::string &))
{
    _resolver = new boost::asio::ip::tcp::resolver(_io_context);
    _endpoints = _resolver->resolve(serverAddress, std::to_string(port));
    _socket = new boost::asio::ip::tcp::socket(_io_context);
    boost::asio::connect(*_socket, _endpoints);
    _socket->async_read_some(boost::asio::buffer(_buf),
                             boost::bind(&ClientWrapper::_handleRead, this,
                                         boost::asio::placeholders::error,
                                         boost::asio::placeholders::bytes_transferred));
            // Faire une fonction private read()
    /*
    size_t len = _socket->read_some(boost::asio::buffer(buf), error);
    if (error == boost::asio::error::eof)
        return ""; // Connection closed cleanly by peer.
    if (error)
        throw boost::system::system_error(error);
    std::string welcomeMessage;
    std::copy(buf.begin(), buf.begin()+ len, std::back_inserter(welcomeMessage));
    return welcomeMessage;*/
}

void uti::network::ClientWrapper::sendMessage(const std::string &message)
{
    boost::asio::async_write(*_socket,
                             boost::asio::buffer(message),
                             [this](boost::system::error_code ec, std::size_t)
                             {
                                 if (ec)
                                     _socket->close();
                             }
    );
}

void uti::network::ClientWrapper::_handleRead(const boost::system::error_code & error,
                                              std::size_t bytesTransferred)
{
    std::cerr << "[DEBUG] handleRead called" << std::endl;
    if (error == boost::asio::error::eof) {
        std::cerr << "[DEBUG] Connection closed" << std::endl;
        _socket->close();
        return; // Connection closed cleanly by peer.
    }
    else if (error)
        throw boost::system::system_error(error);
    std::string messageReceived;
    std::copy(_buf.begin(), _buf.begin()+ bytesTransferred, std::back_inserter(messageReceived));
    std::cerr << "[DEBUG] Message received :" << messageReceived << "FIN" << std::endl;
}
