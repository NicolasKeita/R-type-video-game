/*
** EPITECH PROJECT, 2019
** Graphic.cpp
** File description:
** Graphic.cpp
*/

#include <iostream>
#include <utility>
#include <list>
#include "GraphicWrapper.hpp"

rtype::GraphicWrapper::GraphicWrapper()
        : active { false },
          _background {window }
{}

void rtype::GraphicWrapper::createWindows(size_t width, size_t height)
{
    window.create(sf::VideoMode(width, height), "R-Type");
    active = true;
}

void rtype::GraphicWrapper::_drawBackground()
{
    _background.drawAndMoveBackground();
}

void rtype::GraphicWrapper::setBackground(const std::string & image1,
                                          const std::string & image2)
{
    _background.init_sprite(image1, image2);
}

void rtype::GraphicWrapper::loadAssets()
{
    this->setBackground("assets/background/space.jpg",
                        "assets/background/deathstar.png");
}

void rtype::GraphicWrapper::draw()
{
    this->_drawBackground();
    this->playerBoard.drawOnWindow(window);
    this->playerBoard.drawOnWindow(window);
    for (auto &character : this->characters)
        character.second.drawOnWindow(window);
}

void rtype::GraphicWrapper::addRemoveCharacter(const std::list<Player> &players)
{
    for (auto &player : players) {
        if (characters.find(player) == characters.end()) {
            characters.insert(std::pair<Player, Character>(player, Character({"assets/character/character.png",
                                                                              {40, 195, 100, 100},
                                                                              127,
                                                                              4,
                                                                              CharacterGraphic::Direction::RIGHT},
                                                                             {400, 400})));
        }
    }
}

void rtype::GraphicWrapper::moveCharacters(const std::list<Player> &players, int mainPlayerID)
{
    for (auto &player : players) {
        if (player.ID != mainPlayerID) {
            for (auto &character : characters) {
                if (character.first == player) {
                    sf::Vector2f pos;
                    pos.x = player.posX;
                    pos.y = player.posY;
                    character.second.setPosition(pos);
                }
            }
        }
    }
}