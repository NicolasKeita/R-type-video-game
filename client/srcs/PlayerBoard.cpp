/*
** EPITECH PROJECT, 2019
** PlayerBoard.cpp
** File description:
**
*/

#include <memory>
#include <string>
#include <sstream>
#include <boost/algorithm/string/predicate.hpp>
#include "PlayerBoard.hpp"

rtype::PlayerBoard::PlayerBoard()
        :   firstDataReceived { false }
{}

void rtype::PlayerBoard::drawOnWindow(sf::RenderWindow & window)
{
    for (auto &text : textAreas) {
        window.draw(text);
    }
}

void rtype::PlayerBoard::setText(const std::list<Player> &players)
{
    if (players.empty()) {
        _setTextOneArea("No server detected", -1, -1, 0);
    } else {
        int posYOnScreen = 0;
        for (auto &player : players) {
            _setTextOneArea(std::to_string(player.ID), player.posX, player.posY, posYOnScreen);
            posYOnScreen += 80;
        }
    }
}

void rtype::PlayerBoard::_setTextOneArea(const std::string &PlayerName,
                                          float playerX,
                                          float playerY,
                                          int posYOnScreen)
{
    //auto createText = [&]()
    std::string text;
    std::string old_x;
    std::string old_y;
    std::stringstream new_x;
    std::stringstream new_y;

    new_x << playerX;
    old_x = new_x.str();
    new_y << playerY;
    old_y = new_y.str();
    text = "PlayerID: " + PlayerName + " ; x:" + old_x + "; y:" + old_y;

    sf::Text textArea;
//    auto font = std::make_unique<sf::Font>();
    auto font = new sf::Font();
    font->loadFromFile("assets/arial.ttf");
    textArea.setFont(*font);
    textArea.setString(text);
    textArea.setPosition(1500, static_cast<float>(posYOnScreen));

    static bool once = true;
    if (firstDataReceived && once) {
        textAreas.clear();
        once = false;
    }
    if (textAreas.empty()) {
        textAreas.push_back(textArea);
        return;
    }
    else {
        for (auto &infoPlayer : textAreas) {
            if (boost::starts_with(infoPlayer.getString().toUtf16(),
                                   "PlayerID: " + PlayerName)) {
                infoPlayer = textArea;
                return;
            }
        }
        textAreas.push_back(textArea);
    }
}