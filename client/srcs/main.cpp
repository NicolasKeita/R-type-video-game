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
	graphic.displayPlayerPos("Lilian", 12, 10);  //tu mets tes valeurs pour les coord de ton perso
	sf::Font font;                               //j'ai mis la font ici car je sais pas pourquoi (j'ai vraiment passé 1h) ça crash si je la met dans la fonction displayPlayerPos
	font.loadFromFile("assets/arial.ttf");
	graphic.PlayerPos.setFont(font);
	graphic.createWindows(1920, 1080);
	graphic.setBackground("assets/background/space.jpg",
						  "assets/background/deathstar.png");

	Character c( {"assets/character.png",
			{40,195,100,100},
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
		graphic.drawBackground();;
		graphic._window.draw(graphic.PlayerPos); // là où je draw le text
		c.drawOnWindow(graphic._window);
		graphic._window.display();
	}
	return 0;
}
