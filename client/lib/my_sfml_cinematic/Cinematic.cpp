/*
** EPITECH PROJECT, 2019
** Cinematic.cpp
** File description:
**
*/

#include <string>
#include "Cinematic.hpp"

sf::Sprite    createSpriteFromPath(const std::string  &filename,
                                   const sf::IntRect  &area,
                                   sf::Vector2f       pos,
                                   bool               optionCenterOrigin);

Cinematic::Cinematic()
{
    sf::IntRect     area(0, 0, 960, 720);
    sf::Vector2f    pos = {(1920.f - 970.f) / 2.f, (1080.f - 720.f) / 2.f};

    const std::string     defaultPath = "assets/f.png";

    for (size_t i = 0; i < cinematicSprites.size() ; ++i) {
        std::string path = defaultPath;
        path.insert(14, std::to_string(i + 1));
        cinematicSprites.at(i) = createSpriteFromPath(path, area, pos, false);
    }
}

void Cinematic::start()
{

}