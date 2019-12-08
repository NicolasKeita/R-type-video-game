/*
** EPITECH PROJECT, 2019
** Player_pos.cpp
** File description:
** Player_pos.cpp
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "GraphicWrapper.hpp"

void rtype::GraphicWrapper::displayPlayerPos(std::string PlayerName, int x, int y)
{
	std::string text;
	std::string old_x;
	std::string old_y;
	std::stringstream new_x;
	std::stringstream new_y;

	new_x << x;
	old_x = new_x.str();
	new_y << y;
	old_y = new_y.str();
	text = PlayerName + ":x:" + old_x + "y:" + old_y;
	PlayerPos.setString(text);
	PlayerPos.setPosition(1550, 0);
}
