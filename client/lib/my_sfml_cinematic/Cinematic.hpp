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
#include <array>

class Cinematic {
    public:
        Cinematic();

        int drawOnWindow(sf::RenderWindow &window);

    public:
        static const unsigned int FRAMES_COUNT = 218;
        std::array<sf::Sprite, FRAMES_COUNT> cinematicSprites;


        sf::Clock clock;
        sf::Music music;
        const std::string GAMECUBE_SOUND = "assets/cinematic/gamecube_intro.ogg";
        const std::string CINEMATIC_SPRITES = "assets/cinematic/f.png";
};


#endif //R_TYPE_CINEMATIC_HPP
