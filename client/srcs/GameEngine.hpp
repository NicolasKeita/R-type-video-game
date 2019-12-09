/*
** EPITECH PROJECT, 2019
** GameEngine.hpp
** File description:
**
*/

#ifndef R_TYPE_GAMEENGINE_HPP
#define R_TYPE_GAMEENGINE_HPP

#include <list>
#include <string>
#include <SFML/Graphics.hpp>
#include "Player.hpp"

namespace rtype {
    class GameEngine {
        public:
            GameEngine();

            void saveAllPositions(const std::string &positionsProtocol);
            void updateMainPosition(const sf::Vector2f &pos);

        public:
            std::list<Player> players;
        private:
            void _savePosition(const std::string &info);
    };
}


#endif //R_TYPE_GAMEENGINE_HPP
