/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
**
*/

#include <thread>
#include <boost/algorithm/string/predicate.hpp>
#include "GraphicWrapper.hpp"
#include "Character.hpp"
#include "ClientUdpMultiThreadWrapper.hpp"
#include "Player.hpp"
#include "NetworkManager.hpp"
#include "GameEngine.hpp"
#include "MyProgArgs.hpp"


int main(int argc, char **argv, char **env)
{
    uti::MyProgArgs args(argc, argv, env, 2);
    int port;

    try {
        port = std::stoi(args.getArgs().at(2));
        if (port < 2000) {
            throw std::invalid_argument("Pick higher PORT");
        }
    }
    catch (std::invalid_argument &e) {
        std::cerr << "Wrong port\n" << e.what() << std::endl;
        return 84;
    }

    rtype::GameEngine       gameEngine;
    rtype::GraphicWrapper   graphic;
    NetworkManager network(args.getArgs().at(1), port);

    try {
        std::thread thread(&NetworkManager::handleProtocol, &network, std::ref(gameEngine));

        graphic.createWindows(1920, 1080);
        graphic.setBackground("assets/background/space.jpg",
                              "assets/background/deathstar.png");

        Character c({"assets/character.png",
                     {40, 195, 100, 100},
                     127,
                     4,
                     CharacterGraphic::Direction::RIGHT},
                    {400, 400}); // TODO : put the character inside the graphic class (inside a list of characters)

        while (graphic.window.isOpen()) {
            sf::Event event{};
            while (graphic.window.pollEvent(event)) {
                if (event.type == sf::Event::Closed || !graphic.active)
                    graphic.window.close();
                c.activateKeyboardMvt(event);
            }
            graphic.window.clear();
            using rtype::GameEngine;
            switch (graphic.gameEngine.scene) {
                case GameEngine::INTRO: {
                    int res = graphic.cinematic.drawOnWindow(graphic.window);
                    if (res == 1)
                        graphic.gameEngine.scene = GameEngine::WORLD;
                    break;
                }
                case GameEngine::WORLD : {
                    graphic.drawBackground();
                    graphic.gameEngine.updateMainPosition(c.getPosition());
                    graphic.playerBoard.setText(graphic.gameEngine.players);
                    graphic.playerBoard.drawOnWindow(graphic.window);
                    c.drawOnWindow(graphic.window);
                    break;
                }
                default:
                    break;
            }
            graphic.window.display();
        }
        thread.join();
    }
    catch (std::exception &e) {
        std::cerr << "[R-Type Client] Exception: " << e.what() << std::endl;
        return 2;
    }
    return 0;
}
