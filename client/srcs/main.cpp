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

void handleNetwork(uti::network::ClientUdpMultiThreadWrapper &network, rtype::GraphicWrapper &graphic)
{
    while (true) {
        try {
            if (graphic.gameEngine.players.empty())
                network.sendMessage("IDREQUEST");
            else {
                network.sendMessage("POS " +
                                            std::to_string(graphic.gameEngine.players.front().ID) +
                                            " " + std::to_string(graphic.gameEngine.players.front().posY) +
                                            " " + std::to_string(graphic.gameEngine.players.front().posX));
            }
            std::string reply = network.getReply();
            if (boost::starts_with(reply, "ID")) {
                int idValue = std::stoi(reply.substr(2));
                graphic.gameEngine.players.push_front(rtype::Player(idValue));
            }
            if (boost::starts_with(reply, "POS")) {
                graphic.gameEngine.saveAllPositions(reply);
            }
            if (boost::starts_with(reply, "TERMINATE")) {
                graphic.active = false;
                break;
            }
            //std::cout << "[debug client] server msg : DEBUT" << reply << "FIN" << std::endl;
        } catch (std::invalid_argument &e) {
            std::cerr << "[Rtype client] wrong arg to stoi" << std::endl;
        }
    }
}

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    (void)env;

    try {
        uti::network::ClientUdpMultiThreadWrapper network;
        network.setServer("0.0.0.0", 42424);

        rtype::GraphicWrapper graphic;
        std::thread thread(handleNetwork, std::ref(network), std::ref(graphic));

        graphic.createWindows(1920, 1080);
        graphic.setBackground("assets/background/space.jpg",
                              "assets/background/deathstar.png");

        Character c({"assets/character.png",
                     {40, 195, 100, 100},
                     127,
                     4,
                     CharacterGraphic::Direction::RIGHT},
                    {400, 400}); // TODO : put the character inside the graphic class (inside a list of characters)

        sf::Font font;
        font.loadFromFile("assets/arial.ttf");
        graphic.PlayerPos.setFont(font);

        while (graphic._window.isOpen()) {
            sf::Event event{};
            while (graphic._window.pollEvent(event)) {
                if (event.type == sf::Event::Closed || !graphic.active)
                    graphic._window.close();
                c.activateKeyboardMvt(event);
            }
            graphic._window.clear();
            graphic.drawBackground();
            sf::Vector2f posMyCharacter = c.getPosition();
            if (graphic.gameEngine.players.empty()) {
                graphic.displayPlayerPos("No server detected", -1, -1);
            } else {
                graphic.gameEngine.players.front().posX = posMyCharacter.x;
                graphic.gameEngine.players.front().posY = posMyCharacter.y;
                graphic.displayPlayerPos(std::to_string(graphic.gameEngine.players.front().ID),
                                         graphic.gameEngine.players.front().posX,
                                         graphic.gameEngine.players.front().posY);
            }
            graphic._window.draw(graphic.PlayerPos);
            c.drawOnWindow(graphic._window);
            graphic._window.display();
        }
        thread.join();
    }
    catch (std::exception &e) {
        std::cerr << "[R-Type Client] Exception: " << e.what() << std::endl;
        return 2;
    }
    return 0;
}
