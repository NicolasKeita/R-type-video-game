/*
** EPITECH PROJECT, 2019
** CharacterGraphic.hpp
** File description:
**
*/

#ifndef MY_SFML_CHARACTER_CHARACTERGRAPHIC_HPP
#define MY_SFML_CHARACTER_CHARACTERGRAPHIC_HPP

struct CharacterGraphic
{
    enum Direction { RIGHT, LEFT, UP, BOTTOM };

    std::string         pathImage;
    sf::IntRect         areaFirstFrame;
    int                 offset;
    unsigned int        frameCount;
    Direction           direction;
};

#endif //MY_SFML_CHARACTER_CHARACTERGRAPHIC_HPP
