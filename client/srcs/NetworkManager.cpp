/*
** EPITECH PROJECT, 2019
** NetworkManager.cpp
** File description:
**
*/

#include <boost/algorithm/string/predicate.hpp>
#include "NetworkManager.hpp"

NetworkManager::NetworkManager(const std::string &addressServer,
                               unsigned int port)
{
   _udp.setServer(addressServer, port);
}

void NetworkManager::handleProtocol(rtype::GameEngine &gameEngine)
{
    while (true) {
        // send a message every 1000 milliseconds
        if (_clock.getElapsedTime().asMilliseconds() > 1000) {
            const std::string msg = protocolDecideWhichMessageToSend(gameEngine);
            std::string reply;
            try {
                _udp.sendMessage(msg);
                _clock.restart();

                // Blocking function
                reply = _udp.getReply();
            } catch (const boost::system::system_error &e) { // correct shutdown of the network
                return;
            }
            int stopProgram = protocolHandleReceivedMessages(reply, gameEngine);
            if (stopProgram)
                return;
        }
        //std::cout << "[debug client] server msg : DEBUT" << reply << "FIN" << std::endl;
    }
}

std::string NetworkManager::protocolDecideWhichMessageToSend(const rtype::GameEngine &gameEngine)
{
    std::string msg;

    if (gameEngine.players.empty())
        msg = "IDREQUEST";
    else {
        msg = "POS " +
              std::to_string(gameEngine.players.front().ID) +
              "  " + std::to_string(gameEngine.players.front().posY) +
              "  " + std::to_string(gameEngine.players.front().posX);
    }
    return msg;
}

int NetworkManager::protocolHandleReceivedMessages(const std::string &reply, rtype::GameEngine &gameEngine)
{
    if (boost::starts_with(reply, "ID")) {
        int idValue = std::stoi(reply.substr(2));
        gameEngine.players.push_front(rtype::Player(idValue));
    }
    if (boost::starts_with(reply, "POS")) {
        std::cerr << "MessageReceivedDEBUT" << reply << "FIN" << std::endl;
        gameEngine.saveAllPositions(reply);
//                gameEngine.firstDataReceived = true;
//                graphic.playerBoard.firstDataReceived = true;
    }
    if (boost::starts_with(reply, "TERMINATE")) {
        gameEngine.scene = rtype::GameEngine::END;
        return 1;
    }
    return 0;
}

void NetworkManager::stop()
{
    _udp.stop();
}