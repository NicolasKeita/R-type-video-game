/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
**
*/

#include <thread>
#include "GraphicWrapper.hpp"
#include "Character.hpp"
#include "NetworkManager.hpp"
#include "GameEngine.hpp"
#include "MyProgArgs.hpp"

NetworkManager createNetwork(const uti::MyProgArgs &args)
{
    int port = 0;

    try {
        port = std::stoi(args.getArgs().at(2));
        if (port < 2000) {
            throw std::invalid_argument("Pick higher PORT");
        }
    }
    catch (std::invalid_argument &e) {
        std::cerr << "Wrong port\n" << e.what() << std::endl;
        exit(84);
    }
    return NetworkManager(args.getArgs().at(1), port);
}

int main(int argc, char **argv, char **env)
{
    uti::MyProgArgs         args(argc, argv, env, 2);

    rtype::GameEngine       gameEngine;
    rtype::GraphicWrapper   graphic;

    // Network in another thread
    NetworkManager          network = createNetwork(args);
    std::thread             thread(&NetworkManager::handleProtocol,
                                   &network,
                                   std::ref(gameEngine));

    try
    {
        graphic.createWindows(1920, 1080);
        //graphic.window.setVisible(false); // TODO remove
        graphic.loadAssets();

        while (graphic.window.isOpen()) {
            sf::Event event{};
            while (graphic.window.pollEvent(event)) {
                if (event.type == sf::Event::Closed || !graphic.active) {
                    gameEngine.scene = rtype::GameEngine::END;
                    network.stop();
                    graphic.window.close();
                    break;
                }
                for (auto &character : graphic.characters)
                    character.activateKeyboardMvt(event);
            }
            graphic.window.clear();

            using rtype::GameEngine;
            switch (gameEngine.scene) {
                case GameEngine::INTRO: {
                    int res = graphic.cinematic.drawOnWindow(graphic.window);
                    if (res == 1)
                        gameEngine.scene = GameEngine::WORLD;
                    break;
                }
                case GameEngine::WORLD : {
                    graphic.drawBackground();
                    gameEngine.updateMainPosition(graphic.characters.front().getPosition());
                    graphic.playerBoard.setText(gameEngine.players);
                    graphic.playerBoard.drawOnWindow(graphic.window);
                    for (auto &character : graphic.characters)
                        character.drawOnWindow(graphic.window);
                    break;
                }
                default:
                    break;
            }
            graphic.window.display();
        }
    } catch (const boost::system::system_error &e) { // correct shutdown of the network
        thread.join();
    } catch (std::exception &e) {
        std::cerr << "[R-Type Client] Exception: " << e.what() << std::endl;
        thread.join();
        return 84;
    }
    if (thread.joinable())
        thread.join();
    return 0;
}
