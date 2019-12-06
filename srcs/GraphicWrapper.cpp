/*
** EPITECH PROJECT, 2019
** Graphic.cpp
** File description:
** Graphic.cpp
*/

#include <iostream>
#include "GraphicWrapper.hpp"

rtype::GraphicWrapper::GraphicWrapper()
        : _background { _window }
{}

void rtype::GraphicWrapper::createWindows(size_t width, size_t height)
{
    _window.create(sf::VideoMode(width, height), "R-Type");
}

void rtype::GraphicWrapper::displayBackground()
{
    _background.displayAndMoveBackground();
}

void rtype::GraphicWrapper::setBackground(const std::string & image1,
                                          const std::string & image2)
{
    _background.init_sprite(image1, image2);
}