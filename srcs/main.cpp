/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
**
*/

#include <iostream>
#include "background.hpp"
#include "Graphic.hpp"

int main(int argc, char **argv, char **env)
{
	Background Background;
	GraphicWrapper GraphicWrapper;
	GraphicWrapper.createWindows(1920, 1080);
	Background.display(&GraphicWrapper.window);
	return 0;
}
