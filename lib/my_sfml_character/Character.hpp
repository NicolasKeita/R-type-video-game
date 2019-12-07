/*
** EPITECH PROJECT, 2019
** Character.hpp
** File description:
**
*/

#ifndef R_TYPE_CLIENT_CHARACTER_HPP
#define R_TYPE_CLIENT_CHARACTER_HPP

#include <string>
#include <array>
#include <SFML/Graphics.hpp>
#include "CharacterGraphic.hpp"

class Character {
    public:
        Character(CharacterGraphic graphic, const sf::Vector2f &pos);

        void fillSpriteAnim(CharacterGraphic graphic);
        void drawOnWindow(sf::RenderWindow &_window);

        enum Direction { RIGHT, LEFT, UP, BOTTOM };

    private:
        CharacterGraphic _graphic;
        bool             _displayable;
        sf::Vector2f     _posOnScreen;
        Direction        _currentDirection;
        unsigned int     _currentFrame;
        sf::Clock        _clockMovement;
        sf::Clock        _clockFrame;
        sf::FloatRect   _boundariesMvt;
        sf::Vector2f    _sizeSprite;
        float           _distancePerMove;
        std::array<std::vector<sf::Sprite>, 4> _sprites;

        const float SPEED_FRAME = 4.f;
};


#endif //R_TYPE_CLIENT_CHARACTER_HPP
