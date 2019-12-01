/*
** EPITECH PROJECT, 2019
** background.hpp
** File description:
** background.hpp
*/

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class Background
{
public:
	void display(sf::RenderWindow *window);
	void init_sprite();
	void move_background();
	sf::Time t1 = sf::seconds(0.01f);
	sf::Clock clock;
	float sec = t1.asSeconds();
	float sec2 = t1.asSeconds();
	int a = 0;
	int b = 1500;
	int c = -500;
	sf::Texture texture_bg1;
    sf::Texture texture_bg2;
    sf::Texture texture_deathstar;
    sf::Sprite sprite_bg1;
	sf::Sprite sprite_bg2;
	sf::Sprite sprite_deathstar;
};

#endif
