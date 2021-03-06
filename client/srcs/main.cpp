/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
**
*/

#include <thread>
#include <string>
#include "GraphicWrapper.hpp"
#include "Character.hpp"
#include "NetworkManager.hpp"
#include "GameEngine.hpp"
#include "MyProgArgs.hpp"

NetworkManager createNetwork(const uti::MyProgArgs &args)
{
    int         port = 42424;
    std::string serverAddress = "0.0.0.0";

    if (args.getSize() > 1) {
        try {
            port = std::stoi(args.getArgs().at(2));
            if (port < 2000)
                throw std::invalid_argument("Pick higher PORT");
            serverAddress = args.getArgs().at(1);
        }
        catch (std::invalid_argument & e) {
            std::cerr << "Wrong port\n" << e.what() << std::endl;
            exit(84);
        }
    }
    return NetworkManager(serverAddress, port);
}

int main(int argc, char **argv, char **env)
{
    uti::MyProgArgs         args(argc, argv, env, 0);

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
                for (auto &character : graphic.characters) {
                    if (character.first.ID == gameEngine.mainPlayerID) {
                        character.second.activateKeyboardMvt(event);
                        break;
                    }
                }
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
                    gameEngine.updateMainCharacterPosition(graphic.characters);
                    graphic.playerBoard.setText(gameEngine.players);
                    graphic.addRemoveCharacter(gameEngine.players);
                    graphic.moveCharacters(gameEngine.players, gameEngine.mainPlayerID);
                    graphic.draw();
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
