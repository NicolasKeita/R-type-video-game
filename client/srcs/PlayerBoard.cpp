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
{
    font.loadFromFile("assets/arial.ttf");
    _setTextOneArea(textNoServerDetected, "No server detected", -1, -1, 0);
}

void rtype::PlayerBoard::drawOnWindow(sf::RenderWindow & window)
{
    if (textAreas.empty())
        window.draw(textNoServerDetected);
    else {
        for (auto &text : textAreas) {
            window.draw(text);
        }
    }
}

void rtype::PlayerBoard::setText(const std::list<Player> &players)
{
    if (!players.empty()) {
        /*
        int posYOnScreen = 0;
        for (auto &player : players) {
            _setTextOneArea(
                    std::to_string(player.ID),
                            player.posX,
                            player.posY,
                            posYOnScreen);
            posYOnScreen += 80;
        }*/
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
        std::string old_x;
        std::string old_y;
        std::stringstream new_x;
        std::stringstream new_y;

        new_x << playerX;
        old_x = new_x.str();
        new_y << playerY;
        old_y = new_y.str();
        return "PlayerID: " + PlayerName + " ; x:" + old_x + "; y:" + old_y;
    };
    auto createTextGraphic = [&]()
    {
        std::string text = createText();
        sf::Text textArea;
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
    }

    /*
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
    }*/
}