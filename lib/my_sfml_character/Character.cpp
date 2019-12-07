/*
** EPITECH PROJECT, 2019
** Character.cpp
** File description:
**
*/

#include <SFML/Graphics.hpp>
#include <utility>
#include "Character.hpp"

//TODO : move this proto
sf::Sprite    createSpriteFromPath(const std::string  &filename,
                                   const sf::IntRect  &area,
                                   sf::Vector2f       pos,
                                   bool               optionCenterOrigin);

Character::Character(CharacterGraphic graphic, const sf::Vector2f &pos)
        : _graphic { std::move(graphic) },
          _displayable { true },
          _posOnScreen { pos },
          _currentDirection { Direction::RIGHT },
          _currentFrame { 0 },
          _boundariesMvt { 0.f, 0.f, 1920.f, 1080.f },
          _sizeSprite {static_cast<float>(_graphic.areaFirstFrame.width),
                       static_cast<float>(_graphic.areaFirstFrame.height) },
          _distancePerMove { 40.f },
          _sprites {}
{
    graphic.direction = CharacterGraphic::Direction::RIGHT;
    fillSpriteAnim(graphic);
    graphic.direction = CharacterGraphic::Direction::LEFT;
    fillSpriteAnim(graphic);
    graphic.direction = CharacterGraphic::Direction::BOTTOM;
    fillSpriteAnim(graphic);
    graphic.direction = CharacterGraphic::Direction::UP;
    fillSpriteAnim(graphic);
}

void Character::fillSpriteAnim(CharacterGraphic graphic)
{

    sf::IntRect area_tmp = _graphic.areaFirstFrame;

    for (unsigned int i = 0; i < _graphic.frameCount; ++i) {
        _sprites.at(_graphic.direction).push_back(
                createSpriteFromPath(_graphic.pathImage,
                                     area_tmp,
                                     _posOnScreen,
                                     false));
        area_tmp.left += _graphic.offset;
    }
}

void Character::drawOnWindow(sf::RenderWindow &window)
{
    sf::Time elapsed = _clockFrame.restart();
    static long double sum = 0;

    if (_displayable)
    {
        sum += SPEED_FRAME * elapsed.asMicroseconds() / 1000000.f;
        _currentFrame = static_cast<unsigned int>(sum);
        if (_currentFrame >= _sprites.at(_currentDirection).size()) {
            sum = 0;
            _currentFrame = 0;
        }
        window.draw(_sprites.at(_currentDirection).at(_currentFrame));
    }
}