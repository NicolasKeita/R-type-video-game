/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
**
*/

#include "GraphicWrapper.hpp"

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    (void)env;

	rtype::GraphicWrapper graphic;
	graphic.createWindows(1920, 1080);
	// TODO: move ressources/* to folder assets/background
    graphic.setBackground("ressources/space.jpg",
                          "ressources/deathstar.png");
    graphic.displayBackground();
	return 0;
}
