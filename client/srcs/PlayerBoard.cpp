/*
** EPITECH PROJECT, 2019
** PlayerBoard.cpp
** File description:
**
*/

#include <string>
#include <sstream>
#include <iostream>
#include "PlayerBoard.hpp"

rtype::PlayerBoard::PlayerBoard()
        :   firstDataReceived { false }
{
    font.loadFromFile("assets/font/arial.ttf");
    _setTextOneArea(textNoServerDetected, "No server detected", -1, -1, 0);
}

void rtype::PlayerBoard::drawOnWindow(sf::RenderWindow & window)
{
    if (mapTextAreas.empty())
        window.draw(textNoServerDetected);
    else {
        for (auto &text : mapTextAreas) {
            window.draw(text.second);
        }
    }
}

void rtype::PlayerBoard::setText(const std::list<Player> &players)
{
    int posYOnScreen = 0;
    for (auto &player : players) {
        _setTextOneArea(mapTextAreas[player],
                        std::to_string(player.ID),
                        player.posX,
                        player.posY,
                        posYOnScreen);
        posYOnScreen += 80;
    }
}

void rtype::PlayerBoard::_setTextOneArea(sf::Text &textGraphic,
                                         const std::string &PlayerName,
                                         float playerX,
                                         float playerY,
                                         int posYOnScreen)
{
    auto createText = [&]()
    {
        std::string         old_x;
        std::string         old_y;
        std::stringstream   new_x;
        std::stringstream   new_y;

        new_x << playerX;
        old_x = new_x.str();
        new_y << playerY;
        old_y = new_y.str();
        return "PlayerID: " + PlayerName + " ; x:" + old_x + "; y:" + old_y;
    };
    auto createTextGraphic = [&]()
    {
        std::string text = createText();
        sf::Text    textArea;
        textArea.setFont(font);
        textArea.setString(text);
        textArea.setPosition(1500, static_cast<float>(posYOnScreen));
        return textArea;
    };

    if (textGraphic.getFont() == nullptr) {
        textGraphic = createTextGraphic();
    } else {
        std::string text = createText();
        textGraphic.setString(text);
        textGraphic.setPosition(1500, static_cast<float>(posYOnScreen));
    }
}