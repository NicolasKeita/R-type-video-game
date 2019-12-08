/*
** EPITECH PROJECT, 2019
** GameInfo.hpp
** File description:
**
*/

#ifndef R_TYPE_GAMEINFO_HPP
#define R_TYPE_GAMEINFO_HPP

#include <list>
#include <string>
#include "Player.hpp"

namespace rtype {
    class GameInfo {
        public:
            GameInfo();

            void savePosition(const std::string &msgProtocol);
            std::string allPositionInOneString();

        public:

            std::list<Player> players;
    };
}


#endif //R_TYPE_GAMEINFO_HPP
