/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
**
*/

#include "GraphicWrapper.hpp"
#include "Character.hpp"

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    (void)env;

    rtype::GraphicWrapper graphic;
    graphic.createWindows(1920, 1080);
    // TODO: move ressources/* to folder assets/background
    graphic.setBackground("ressources/space.jpg",
                          "ressources/deathstar.png");

    // TODO : transform the character creation to less lines
    CharacterGraphic gr;
    gr.pathImage = "ressources/character.png";
    gr.areaFirstFrame = {40,
                         195,
                         100,
                         100};
    gr.offset = 127;
    gr.frameCount = 4;
    gr.direction = CharacterGraphic::Direction::RIGHT;
    Character c(gr, {400, 400}); // TODO : put the character inside the graphic class (inside a list of characters)
    // TODO : fin character creation

    while (graphic._window.isOpen()) {
        sf::Event event{};
        while (graphic._window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                graphic._window.close();
            c.activateKeyboardMvt(event);
        }
        graphic._window.clear();
        graphic.drawBackground();
        c.drawOnWindow(graphic._window);
        graphic._window.display();
    }
    return 0;
}
