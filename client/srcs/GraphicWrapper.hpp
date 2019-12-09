/*
** EPITECH PROJECT, 2019
** Graphic.hpp
** File description:
** Graphic.hpp
*/

#ifndef GRAPHICWRAPPER_H_
#define GRAPHICWRAPPER_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "IGraphicWrapper.hpp"
#include "Background.hpp"
#include "GameEngine.hpp"
#include "PlayerBoard.hpp"

namespace rtype {
    class GraphicWrapper : public IGraphicWrapper {
        public:
            GraphicWrapper();
            void createWindows(size_t width, size_t height) override;
            void drawBackground() override;
            void setBackground(const std::string &image1, const std::string &image2) override;

        public:
            sf::RenderWindow    window;
            GameEngine          gameEngine;
//            sf::Text            PlayerPos;
            PlayerBoard         playerBoard;
            bool                active;
        private:
            Background       _background;
    };
}

#endif
