/*
** EPITECH PROJECT, 2019
** Player.hpp
** File description:
**
*/

#ifndef R_TYPE_PLAYER_HPP
#define R_TYPE_PLAYER_HPP

namespace rtype {
    class Player {
        public:
            explicit Player(int id) : ID { id } {};

            int ID;
            float posX;
            float posY;
    };
}

#endif //R_TYPE_PLAYER_HPP
