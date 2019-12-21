/*
** EPITECH PROJECT, 2019
** GameEngine.cpp
** File description:
**
*/

#include <vector>
#include <iostream>
#include "GameEngine.hpp"
#include "MyStrTok.hpp"

rtype::GameEngine::GameEngine() : scene { WORLD }, mainPlayerID { -2 }
{

}

void rtype::GameEngine::saveAllPositions(const std::string & positionsProtocol)
{
    //const std::string &         str = positionsProtocol;
    std::vector<std::string>    playerInfos;

    uti::myStrTok(positionsProtocol, playerInfos, ";");
    for (const std::string &playerInfo : playerInfos)
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

void rtype::GameEngine::updateMainCharacterPosition(std::map<Player, Character> characters)
{
    if (!players.empty()) {
        for (auto &player : players) {
            if (player.ID == this->mainPlayerID) {
                std::for_each(characters.begin(), characters.end(),
                              [&player](const std::pair<Player, Character> &character) {
                                  if (player == character.first) {
                                      player.posX = character.second.getPosition().x;
                                      player.posY = character.second.getPosition().y;
                                  }
                              });
                break;
            }
        }
    }
}
