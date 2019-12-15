/*
** EPITECH PROJECT, 2019
** background.hpp
** File description:
** background.hpp
*/

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

//TODO put a namespace
class Background {
    public:
        explicit Background(sf::RenderWindow & window);

        void init_sprite(const std::string &image1, const std::string &image2);
        void drawAndMoveBackground();

        //TODO: turn everything else to private
        void move_background();
        sf::Time    t1 = sf::seconds(0.01f);
        sf::Clock   clock;
        float       sec = t1.asSeconds();
        float       sec2 = t1.asSeconds();
        float       a = 0.f;
        float       b = 1500.f;
        float       c = -500.f;
        sf::Texture texture_bg1;
        sf::Texture texture_bg2;
        sf::Texture texture_deathstar;
        sf::Sprite  sprite_bg1;
        sf::Sprite  sprite_bg2;
        sf::Sprite  sprite_deathstar;

    private:
        sf::RenderWindow & _window;
};

#endif
