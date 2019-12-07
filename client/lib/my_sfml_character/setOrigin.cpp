/*
** EPITECH PROJECT, 2019
** setOrigin.cpp
** File description:
**
*/

#include <SFML/Graphics.hpp>

//TODO : move this function to an independant lib
void setOriginMiddle(sf::Sprite &sprite)
{
    sf::Vector2f    origin;
    sf::FloatRect   rect;

    rect = sprite.getGlobalBounds();
    origin.x = rect.width / 2.f;
    origin.y = rect.height / 2.f;
    sprite.setOrigin(origin);
}
