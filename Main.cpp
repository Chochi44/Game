#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 700), "SFML works!");
	//sf::CircleShape shape(100.f);
	sf::RectangleShape rect(sf::Vector2f(10.0f, 10.0f));
	sf::Texture corgi;
	corgi.loadFromFile("corgi.png");
	rect.setTexture(&corgi);

	Game* game = new Game(5, &window);

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