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
        try {
            if (gameEngine.players.empty())
                _udp.sendMessage("IDREQUEST");
            else {
                _udp.sendMessage("POS " +
                                        std::to_string(gameEngine.players.front().ID) +
                                        "  " + std::to_string(gameEngine.players.front().posY) +
                                        "  " + std::to_string(gameEngine.players.front().posX));
                }
            std::string reply = _udp.getReply();
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
                break;
            }
            //std::cout << "[debug client] server msg : DEBUT" << reply << "FIN" << std::endl;
            } catch (std::invalid_argument &e) {
                std::cerr << "[Rtype client] wrong arg to stoi" << std::endl;
            }
        }
}