/*
** EPITECH PROJECT, 2019
** Character.cpp
** File description:
**
*/

#include <SFML/Graphics.hpp>
#include <utility>
#include <cmath>
#include "Character.hpp"

//TODO : move this proto to a hpp
sf::Sprite    createSpriteFromPath(const std::string  &filename,
                                   const sf::IntRect  &area,
                                   sf::Vector2f       pos,
                                   bool               optionCenterOrigin);

Character::Character(CharacterGraphic graphic, const sf::Vector2f &pos)
        : _graphic { std::move(graphic) },
          _displayable { true },
          _posOnScreen { pos },
          _currentDirection {static_cast<Direction>(_graphic.direction)},
          _currentFrame { 0 },
          _boundariesMvt { 0.f, 0.f, 1920.f, 1080.f },
          _sizeSprite {static_cast<float>(_graphic.areaFirstFrame.width),
                       static_cast<float>(_graphic.areaFirstFrame.height) },
          _distancePerMove { 40.f },
          _sprites {}
{
    graphic.direction = CharacterGraphic::Direction::RIGHT;
    _fillSpriteAnim(graphic);
    graphic.direction = CharacterGraphic::Direction::LEFT;
    _fillSpriteAnim(graphic);
    graphic.direction = CharacterGraphic::Direction::BOTTOM;
    _fillSpriteAnim(graphic);
    graphic.direction = CharacterGraphic::Direction::UP;
    _fillSpriteAnim(graphic);
}

void Character::_fillSpriteAnim(CharacterGraphic &graphic)
{
    sf::IntRect area_tmp = _graphic.areaFirstFrame;

    for (unsigned int i = 0; i < _graphic.frameCount; ++i) {
        _sprites.at(graphic.direction).push_back(
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
        sum += SPEED_FRAME * elapsed.asMicroseconds() / pow(10, 6);
        _currentFrame = static_cast<unsigned int>(sum);
        if (_currentFrame >= _sprites.at(_currentDirection).size()) {
            sum = 0;
            _currentFrame = 0;
        }
        window.draw(_sprites.at(_currentDirection).at(_currentFrame));
    }
}

void Character::activateKeyboardMvt(sf::Event &event)
{
    if (event.type != event.KeyPressed)
        return;
    if (event.key.code == sf::Keyboard::Z ||
            event.key.code == sf::Keyboard::Q ||
            event.key.code == sf::Keyboard::D ||
            event.key.code == sf::Keyboard::S)
    {
        if (_clockMovement.getElapsedTime().asMicroseconds() > 0.5 * pow(10, -6)) {
            _clockMovement.restart();
        }
    }
    sf::Vector2f offset;

    if (event.key.code == sf::Keyboard::Z) {
        if (_posOnScreen.y < _boundariesMvt.top)
            return;
        _currentDirection = Character::Direction::UP;
        offset = sf::Vector2f(0, -_distancePerMove);
        this->move(offset);
    }
    if (event.key.code == sf::Keyboard::S) {
        if (_posOnScreen.y > _boundariesMvt.height - _sizeSprite.y)
            return;
        _currentDirection = BOTTOM;
        offset = sf::Vector2f(0, _distancePerMove);
        this->move(offset);
    }
    if (event.key.code == sf::Keyboard::Q) {
        if (_posOnScreen.x < _boundariesMvt.left)
            return;
        _currentDirection = LEFT;
        offset = sf::Vector2f(-_distancePerMove, 0);
        move(offset);
    }
    if (event.key.code == sf::Keyboard::D) {
        if (_posOnScreen.x > _boundariesMvt.width - _sizeSprite.x)
            return;
        _currentDirection = RIGHT;
        offset = sf::Vector2f(_distancePerMove, 0);
        move(offset);
    }
}

void Character::move(const sf::Vector2f & offset)
{
    for (auto & spritesDirection : _sprites) {
        for (auto & sprite : spritesDirection) {
            sprite.move(offset);
        }
    }
    sf::FloatRect rect = _sprites.at(0).at(0).getGlobalBounds();
    _posOnScreen.x = rect.left;
    _posOnScreen.y = rect.top;
}

void Character::setPosition(const sf::Vector2f &pos)
{
    for (auto & spritesDirection : _sprites) {
        for (auto & sprite : spritesDirection) {
            sprite.setPosition(pos);
        }
    }
    sf::FloatRect rect = _sprites.at(0).at(0).getGlobalBounds();
    _posOnScreen.x = rect.left;
    _posOnScreen.y = rect.top;
}

sf::Vector2f Character::getPosition() const
{
    return _posOnScreen;
}

sf::Vector2f Character::getSize() const
{
    return _sizeSprite;
}

void Character::setDistancePerMove(float distancePerMove)
{
    _distancePerMove = distancePerMove;
}

/*
* rect.left = left; rect.top = top; rect.width = right; rect.height = bottom
*/
void Character::setBoundariesMvt(const sf::FloatRect &rect)
{
    _boundariesMvt = rect;
}

void Character::setScale(float scale)
{
    sf::Vector2f scaleVector(scale, scale);

    for (auto & spritesDirection : _sprites) {
        for (auto & sprite : spritesDirection) {
            sprite.setScale(scaleVector);
        }
    }
}