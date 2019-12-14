/*
** EPITECH PROJECT, 2019
** Cinematic.cpp
** File description:
**
*/

#include <string>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "Cinematic.hpp"

sf::Sprite    createSpriteFromPath(const std::string  &filename,
                                   const sf::IntRect  &area,
                                   sf::Vector2f       pos,
                                   bool               optionCenterOrigin);

Cinematic::Cinematic()
{
    // load sprites
    sf::IntRect     area(0, 0, 960, 720);
    sf::Vector2f    pos = {(1920.f - 970.f) / 2.f, (1080.f - 720.f) / 2.f};

    for (size_t i = 0; i < cinematicSprites.size() ; ++i) {
        std::string path = CINEMATIC_SPRITES;
        size_t indexBeforeExtension = path.size() - 4;
        path.insert(indexBeforeExtension, std::to_string(i + 1));
        cinematicSprites.at(i) = createSpriteFromPath(path, area, pos, false);
    }

    //load sound
    music.openFromFile(GAMECUBE_SOUND);
    music.setVolume(100.f);
}

// returns 1 when the movie is finished
int Cinematic::drawOnWindow(sf::RenderWindow &window)
{
    static long double  sum = 0;
    static bool         firstTime = true;
    static unsigned int currentFrame = 0;

    sf::Time elapsed = clock.restart();
    sum += (30.f * elapsed.asMicroseconds()) / pow(10, 6);
    if (!firstTime) {
        currentFrame = static_cast<unsigned int>(sum);
        if (currentFrame >= FRAMES_COUNT)
            return 1;
    }
    if (firstTime) {
        music.play();
        currentFrame = 1;
        firstTime = false;
        sum = 0;
    }
    window.draw(cinematicSprites.at(currentFrame));
    return 0;
}