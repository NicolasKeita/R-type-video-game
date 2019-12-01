/*
** EPITECH PROJECT, 2019
** Graphic.hpp
** File description:
** Graphic.hpp
*/

#ifndef GRAPHICWRAPPER_H_
#define GRAPHICWRAPPER_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class GraphicWrapper
{
public:
	void createWindows(size_t width, size_t height);
	sf::RenderWindow window;
};

#endif
