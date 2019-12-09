/*
** EPITECH PROJECT, 2019
** GameInfo.cpp
** File description:
**
*/

#include <cstdlib>
#include <iostream>
#include <vector>
#include "MyStrTok.hpp"
#include "GameInfo.hpp"

rtype::GameInfo::GameInfo()
{

}

void rtype::GameInfo::savePosition(const std::string & msgProtocol)
{
    std::cerr << "Message proto:" << msgProtocol << "FIN" << std::endl;
    std::vector<std::string> positionToken;
    uti::myStrTok(msgProtocol, positionToken, " ");
    Player p{};
    p.ID = std::stoi(positionToken.at(1));
    p.posY = std::stof(positionToken.at(2));
    p.posX = std::stof(positionToken.at(3));
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

std::string rtype::GameInfo::allPositionInOneString()
{
    std::string str;

    for (auto &player : players) {
        str += "POS ";
        str += std::to_string(player.ID);
        str += " ";
        str += std::to_string(player.posY);
        str += " ";
        str += std::to_string(player.posX);
        if (players.back().ID != player.ID)
            str += ";";
    }
    return str;
}