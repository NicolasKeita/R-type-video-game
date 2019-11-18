/*
** EPITECH PROJECT, 2019
** ServerWrapper.cpp
** File description:
**
*/

#include <string>
#include <cstdlib>
#include <boost/smart_ptr/make_shared.hpp>
#include <utility>
#include "ServerWrapper.hpp"

uti::network::ServerWrapper::ServerWrapper()
        : _welcomeMessage { "" },
          _handleMessageReceived { nullptr },
          _acceptor { nullptr }
{

}

void uti::network::ServerWrapper::turnOn(unsigned int port,
                                         std::string (*handleMessageReceived)(const std::string &),
                                         const std::string &welcomeMessage)
{
    _welcomeMessage = welcomeMessage;
    _handleMessageReceived = handleMessageReceived;
    _acceptor = new boost::asio::ip::tcp::acceptor(_io_context, tcp::endpoint(tcp::v4(), port));
    if (_welcomeMessage.back() != '\n')
        _welcomeMessage += '\n';
    _startAccept();
    _io_context.run();
}

/*
uti::network::ServerWrapper::ServerWrapper(unsigned int port,
                                             std::string (*handleMessageReceived)(const std::string &),
                                             const std::string &welcomeMessage)
        : _welcomeMessage { welcomeMessage },
          _handleMessageReceived { handleMessageReceived },
          _acceptor { _io_context, tcp::endpoint(tcp::v4(), port) }
{
    if (_welcomeMessage.back() != '\n')
        _welcomeMessage += '\n';
            _startAccept();
    _io_context.run();
}*/

void uti::network::ServerWrapper::_startAccept()
{
    auto newConnection =
            boost::make_shared<typename uti::network::ServerWrapper::TcpConnection>(_io_context,
                                                                                      _welcomeMessage,
                                                                                      _handleMessageReceived);
    _acceptor->async_accept(newConnection->socket(),
                           boost::bind(&ServerWrapper::_handleAccept,
                                       this,
                                       newConnection,
                                       boost::asio::placeholders::error));
}

void uti::network::ServerWrapper::_handleAccept(const boost::shared_ptr<uti::network::ServerWrapper::TcpConnection> &new_connection,
                                                  const boost::system::error_code &error)
{
    if (!error) {
        new_connection->start();
        _all_clients.push_back(new_connection);
    }
    _startAccept();
}

void uti::network::ServerWrapper::sendMessageToTheLastestClient(const std::string &message)
{
    if (_welcomeMessage.back() != '\n')
        _welcomeMessage += '\n';
    _all_clients.back()->sendMessage(message);
}

uti::network::ServerWrapper::TcpConnection::TcpConnection(boost::asio::io_context &io_context,
                                                            std::string welcomeMessage,
                                                            std::string (*handleMessageReceived)(const std::string &))
        : socket_ { io_context },
          _welcomeMessage {std::move( welcomeMessage )},
          _buffer {},
          _handleMessageReceived { handleMessageReceived }
{}

void uti::network::ServerWrapper::TcpConnection::handleRead(const boost::system::error_code & e,
                                                              std::size_t bytesTransferred)
{
    if (e && e != boost::asio::error::eof) {
        std::cerr << "[DEBUG] read failed" << std::endl;
        return;
    }
    std::string messageReceived(_buffer.begin(), _buffer.end());
    int i = 0;
    for (; i < messageReceived.size(); ++i) {
        if (messageReceived[i] == '\0') {
            break;
        }
    }
    messageReceived = std::string(messageReceived.begin(), messageReceived.begin() + i);
    if (messageReceived.back() == '\n') {
        messageReceived.pop_back();
    }
    std::string reply = _handleMessageReceived(messageReceived);
    if (reply != "") {
        if (reply.back() != '\n')
            reply += '\n';
        sendMessage(reply);
    }
    boost::asio::async_read(socket_, boost::asio::buffer(_buffer),
                            boost::asio::transfer_at_least(2),
                            boost::bind(&TcpConnection::handleRead, shared_from_this(),
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::bytes_transferred));
}

void uti::network::ServerWrapper::TcpConnection::handleWrite()
{
    // stuff to do after sending a message
}

void uti::network::ServerWrapper::TcpConnection::sendMessage(const std::string &message)
{
    boost::asio::async_write(socket_, boost::asio::buffer(message),
                             boost::bind(&TcpConnection::handleWrite, shared_from_this()));
}

void uti::network::ServerWrapper::TcpConnection::start()
{
    boost::asio::async_write(socket_, boost::asio::buffer(_welcomeMessage),
                             boost::bind(&TcpConnection::handleWrite, shared_from_this()));
    socket_.async_read_some(boost::asio::buffer(_buffer),
                            boost::bind(&TcpConnection::handleRead, shared_from_this(),
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::bytes_transferred));
}

tcp::socket & uti::network::ServerWrapper::TcpConnection::socket()
{
    return socket_;
}

