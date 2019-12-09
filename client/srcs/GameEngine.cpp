/*
** EPITECH PROJECT, 2019
** GameEngine.cpp
** File description:
**
*/

#include <vector>
#include "GameEngine.hpp"
#include "MyStrTok.hpp"

rtype::GameEngine::GameEngine()
{

}

void rtype::GameEngine::saveAllPositions(const std::string & positionsProtocol)
{
    const std::string& str = positionsProtocol;
    std::vector<std::string> playerInfos;
    uti::myStrTok(str, playerInfos, ";");
    for (std::string &playerInfo : playerInfos)
        _savePosition(playerInfo);
}

void rtype::GameEngine::_savePosition(const std::string &info)
{
    std::vector<std::string> infoToken;
    uti::myStrTok(info, infoToken, " ");
    Player p{};
    p.ID = std::stoi(infoToken.at(1));
    p.posY = std::stof(infoToken.at(2));
    p.posX = std::stof(infoToken.at(3));

    if (players.empty()) {
        players.push_front(p);
        return;
    } else {
        for (Player &player : players) {
            if (player.ID == p.ID) {
                player.posY = p.posY;
                player.posX = p.posX;
                return;
            }
        }
        players.push_front(p);
    }
}

void rtype::GameEngine::updateMainPosition(const sf::Vector2f & pos)
{
    if (!players.empty()) {
        players.front().posX = pos.x;
        players.front().posY = pos.y;
    }
}
