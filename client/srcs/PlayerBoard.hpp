/*
** EPITECH PROJECT, 2019
** playerBoard.hpp
** File description:
**
*/

#ifndef R_TYPE_PLAYERBOARD_HPP
#define R_TYPE_PLAYERBOARD_HPP

#include <list>
#include <SFML/Graphics.hpp>
#include "Player.hpp"

namespace rtype {
    class PlayerBoard {
        public:
            PlayerBoard();

            void setText(const std::list<Player> &players);
            void drawOnWindow(sf::RenderWindow &window);

            std::list<sf::Text> textAreas;
            sf::Text            textNoServerDetected;
            bool                firstDataReceived;
            sf::Font            font;

        private:
            void _setTextOneArea(sf::Text &textGraphic,
                                 const std::string &PlayerName,
                                 float playerX,
                                 float playerY,
                                 int posYOnScreen);
    };
}


#endif //R_TYPE_PLAYERBOARD_HPP
