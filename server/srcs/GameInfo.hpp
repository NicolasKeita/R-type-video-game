/*
** EPITECH PROJECT, 2019
** GameInfo.hpp
** File description:
**
*/

#ifndef R_TYPE_GAMEINFO_HPP
#define R_TYPE_GAMEINFO_HPP

#include <list>
#include "Player.hpp"

namespace rtype {
    class GameInfo {
        public:
            GameInfo();

            std::list<Player> playersID;
    };
}


#endif //R_TYPE_GAMEINFO_HPP
