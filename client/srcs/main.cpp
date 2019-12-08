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

void handleNetwork(uti::network::ClientUdpMultiThreadWrapper &network, rtype::GraphicWrapper &graphic)
{
    while (true) {
        try {
            network.sendMessage("IDREQUEST");
            std::string reply = network.getReply();
            if (boost::starts_with(reply, "ID")) {
                int idValue = std::stoi(reply.substr(2));
                graphic.gameEngine.playersID.push_front(idValue);
            }
            if (boost::starts_with(reply, "TERMINATE"))
                break;
            std::cout << "[client] server msg : DEBUT" << reply << "FIN" << std::endl;
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

        graphic.displayPlayerPos("Lilian", 12, 10);
        sf::Font font;
        font.loadFromFile("assets/arial.ttf");
        graphic.PlayerPos.setFont(font);

        graphic.createWindows(1920, 1080);
        graphic.setBackground("assets/background/space.jpg",
                              "assets/background/deathstar.png");

        Character c({"assets/character.png",
                     {40, 195, 100, 100},
                     127,
                     4,
                     CharacterGraphic::Direction::RIGHT},
                    {400, 400}); // TODO : put the character inside the graphic class (inside a list of characters)

        while (graphic._window.isOpen()) {
            sf::Event event{};
            while (graphic._window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    graphic._window.close();
                c.activateKeyboardMvt(event);
            }
            graphic._window.clear();
            graphic.drawBackground();
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
