/*
** EPITECH PROJECT, 2019
** Graphic.hpp
** File description:
** Graphic.hpp
*/

#ifndef GRAPHICWRAPPER_H_
#define GRAPHICWRAPPER_H_

#include <iostream>
#include <list>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include "IGraphicWrapper.hpp"
#include "Background.hpp"
#include "GameEngine.hpp"
#include "PlayerBoard.hpp"
#include "Cinematic.hpp"
#include "Character.hpp"

namespace std {
    template <>
    struct hash<rtype::Player>
    {
        std::size_t operator()(const rtype::Player & k) const
        {
            return k.ID;
        }
    };
}

namespace rtype {
    class GraphicWrapper : public IGraphicWrapper {
        public:
            GraphicWrapper();
            void createWindows(size_t width, size_t height) override;
            void setBackground(const std::string &image1, const std::string &image2) override;
            void draw() override;

            void loadAssets();
            void addRemoveCharacter(const std::list<Player> &players);
            void moveCharacters(const std::list<Player> &players, int mainPlayerID);

        private:
            void _drawBackground() override;

    public:
            sf::RenderWindow    window;
            Cinematic           cinematic;
            PlayerBoard         playerBoard;
            bool                active;
            std::unordered_map<Player, Character>   characters;
        private:
            Background       _background;
    };
}

#endif
