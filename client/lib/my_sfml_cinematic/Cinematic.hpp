/*
** EPITECH PROJECT, 2019
** Cinematic.hpp
** File description:
**
*/

#ifndef R_TYPE_CINEMATIC_HPP
#define R_TYPE_CINEMATIC_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class Cinematic {
    public:
        Cinematic();

        void start();

    public:
        static const unsigned int FRAMES_COUNT = 218;
        std::array<sf::Sprite, FRAMES_COUNT> cinematicSprites;

        const std::string GAMECUBE_SOUND = "assets/gamecube_intro.ogg";
};


#endif //R_TYPE_CINEMATIC_HPP
