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

        void drawOnWindow(sf::RenderWindow &_window);
        void activateKeyboardMvt(sf::Event &event);
        void move(const sf::Vector2f &offset);

        [[nodiscard]] sf::Vector2f getPosition() const;
        [[nodiscard]] sf::Vector2f getSize() const;

        void setDistancePerMove(float distancePerMove);
        void setBoundariesMvt(const sf::FloatRect &rect);
        void setPosition(const sf::Vector2f &pos);
        void setScale(float scale);

        enum Direction { RIGHT, LEFT, UP, BOTTOM };

    private:
        void _fillSpriteAnim(CharacterGraphic &graphic);
    private:
        CharacterGraphic _graphic;
        bool             _displayable;
        sf::Vector2f     _posOnScreen;
        Direction        _currentDirection;
        unsigned int     _currentFrame;
        sf::Clock        _clockMovement;
        sf::Clock        _clockFrame;
        sf::FloatRect    _boundariesMvt;
        sf::Vector2f     _sizeSprite;
        float            _distancePerMove;
        std::array<std::vector<sf::Sprite>, 4> _sprites;

        static constexpr float SPEED_FRAME = 4.f;
};


#endif //R_TYPE_CLIENT_CHARACTER_HPP
