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
            explicit Player(int id = -1) : ID { id }, posX { -1 }, posY { -1 }, score { - 1 } {};

            bool operator<(const Player &other) const { return ID < other.ID; };

            int ID;
            float posX;
            float posY;
            int score;
    };
}

#endif //R_TYPE_PLAYER_HPP
