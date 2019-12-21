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
#include "Cinematic.hpp"
#include "Character.hpp"

namespace rtype {
    class GameEngine {
        public:
            enum Scene { INTRO, WORLD, END };
            GameEngine();

            void saveAllPositions(const std::string &positionsProtocol);
            void updateMainCharacterPosition(const std::unordered_map<Player, Character> &characters);

        public:
            Scene               scene;
            std::list<Player>   players;
            int                 mainPlayerID;

        private:
            void _savePosition(const std::string &info);
    };
}


#endif //R_TYPE_GAMEENGINE_HPP
