/*
** EPITECH PROJECT, 2019
** Graphic.cpp
** File description:
** Graphic.cpp
*/

#include <iostream>
#include "Graphic.hpp"

void GraphicWrapper::createWindows(size_t width, size_t height)
{
	window.create(sf::VideoMode(width, height), "RTYPE");
}
