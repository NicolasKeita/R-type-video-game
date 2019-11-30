/*
** EPITECH PROJECT, 2019
** background.cpp
** File description:
** background.cpp
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "background.hpp"

void Background::init_sprite()
{
	texture_bg1.loadFromFile("ressources/space.jpg");
	texture_bg2.loadFromFile("ressources/space.jpg");
	texture_deathstar.loadFromFile("ressources/deathstar.png");
	sprite_bg1.setTexture(texture_bg1);
	sprite_bg2.setTexture(texture_bg2);
	sprite_deathstar.setTexture(texture_deathstar);
	sprite_bg2.setPosition(5000, 4000);
}

void Background::move_background()
{
	sf::Time elapsed1 = clock.getElapsedTime();
	sec = elapsed1.asSeconds();
	if (sec - sec2 >= 0.01) {
		sec2 = sec;
		sprite_bg1.setPosition(a, 0);
		sprite_bg2.setPosition(b, 0);
		sprite_deathstar.setPosition(c, 10);
		a = a - 1;
		b = b - 1;
		c = c - 3;
		if (a <= -1800)
			a = 1500;
		if (b <= -1800)
			b = 1500;
		if (c <= -1800)
			c = 1500;
 	}
}

void Background::display(sf::RenderWindow *window)
{
	init_sprite();
	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window->close();
		}
		window->clear();
		window->draw(sprite_bg1);
		window->draw(sprite_bg2);
		window->draw(sprite_deathstar);
		window->display();
		move_background();
	}
}
