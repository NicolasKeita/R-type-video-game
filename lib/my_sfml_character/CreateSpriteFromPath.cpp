/*
** EPITECH PROJECT, 2019
** createSpriteFromPath.cpp
** File description:
**
*/

#include <iostream>
#include <SFML/Graphics.hpp>

//TODO : move this proto
void setOriginMiddle(sf::Sprite &sprite);

sf::Sprite    createSpriteFromPath(const std::string  &filename,
                                   const sf::IntRect  &area,
                                   sf::Vector2f       pos,
                                   bool               optionCenterOrigin)
{
    if (filename.empty())
        return sf::Sprite();
    //TODO : remove new
    auto texture = new sf::Texture;
    if (!texture->loadFromFile(filename)) {
        std::cerr << "[CreateSpriteFromPAth] cannot find image " << filename << std::endl;
        return sf::Sprite();
    }
    sf::Sprite sprite;
    sprite.setTexture(*texture);
    sprite.setTextureRect(area);
    sprite.setPosition(pos);
    if (optionCenterOrigin)
        setOriginMiddle(sprite);
    return sprite;
}
