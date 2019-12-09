/*
** EPITECH PROJECT, 2019
** Graphic.cpp
** File description:
** Graphic.cpp
*/

#include <iostream>
#include <sstream>
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

void rtype::GraphicWrapper::drawBackground()
{
    _background.drawAndMoveBackground();
}

void rtype::GraphicWrapper::setBackground(const std::string & image1,
                                          const std::string & image2)
{
    _background.init_sprite(image1, image2);
}

