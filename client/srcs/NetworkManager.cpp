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
        // Send a message every 70 milliseconds
        if (_clock.getElapsedTime().asMilliseconds() > 70) {
            _mutex.lock();
            const std::string msg = protocolDecideWhichMessageToSend(gameEngine);
            _mutex.unlock();

            std::string reply;
            try {
                _udp.sendMessage(msg);
                _clock.restart();

                // Blocking function
                reply = _udp.getReply();
            } catch (const boost::system::system_error &e) { // correct shutdown of the network
                return;
            }

            _mutex.lock();
            int stopProgram = protocolHandleReceivedMessages(reply, gameEngine);
            _mutex.unlock();
            if (stopProgram)
                return;
        }
    }
}

std::string NetworkManager::protocolDecideWhichMessageToSend(const rtype::GameEngine &gameEngine)
{
    std::string msg;

    if (gameEngine.players.empty())
        msg = "IDREQUEST";
    else {
        std::unique_ptr<rtype::Player> playerPointer;
        for (auto &player : gameEngine.players) {
            if (player.ID == gameEngine.mainPlayerID) {
                playerPointer = std::make_unique<rtype::Player>(player);
                break;
            }
        }
        msg = "POS " + std::to_string(playerPointer->ID) +
                "  " + std::to_string(playerPointer->posY) +
                "  " + std::to_string(playerPointer->posX);
    }
    return msg;
}

int NetworkManager::protocolHandleReceivedMessages(const std::string &reply, rtype::GameEngine &gameEngine)
{
    if (boost::starts_with(reply, "ID")) {
        int idValue = std::stoi(reply.substr(2));
        gameEngine.players.push_front(rtype::Player(idValue));
        gameEngine.mainPlayerID = idValue;
    }
    else if (boost::starts_with(reply, "POS")) {
        gameEngine.saveAllPositions(reply);
    }
    else if (boost::starts_with(reply, "TERMINATE")) {
        gameEngine.scene = rtype::GameEngine::END;
        return 1;
    }
    return 0;
}

void NetworkManager::stop()
{
    _udp.stop();
}