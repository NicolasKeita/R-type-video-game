/*
** EPITECH PROJECT, 2019
** GameEngine.hpp
** File description:
**
*/

#ifndef R_TYPE_GAMEENGINE_HPP
#define R_TYPE_GAMEENGINE_HPP

#include <list>

namespace rtype {
    class GameEngine {
        public:
            GameEngine();

            std::list<int> playersID;
    };
}


#endif //R_TYPE_GAMEENGINE_HPP
