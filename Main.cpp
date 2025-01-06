#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(440, 700), "Trash master!", sf::Style::Titlebar | sf::Style::Close);

	Game* game = new Game(7, &window);

	//Main game loop
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyReleased) {
				if (game->title || game->end) {
					game->start();
				}
				else {

					if (event.key.code == sf::Keyboard::Left) {
						game->moveCartLeft();
					}
					else if (event.key.code == sf::Keyboard::Right) {
						game->moveCartRight();
					}
				}
			}
		}

		if (game->title) {
			game->drawTitle();
		}
		else {
			if (!game->end) {
				game->checkLevel();
				game->scroll();
			}
			game->draw();
		}
	}

	return 0;

}