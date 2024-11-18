#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Lane.h"
#include "Cart.h"
#include "Trash.h"
#include <list>

class Game : public GameControl
{
	Cart* cart;
	std::vector<Lane*>* lanes;
	sf::RenderWindow* window;
	sf::Font* font;

	float scrollPosition;

public:
	int score = 0;
	float laneWidth = 60.0f;
	float cartWidth = 50.0f;
	float cartHeight = 50.0f;

	Game(int lanesNum, sf::RenderWindow* window)
	{
		//Load font
		font = new sf::Font();
		if (!font->loadFromFile("tuffy.ttf"))
		{
			std::cout << "Font not found!";
			window->close();
		}

		this->window = window;
		cart = new Cart(new sf::RectangleShape(sf::Vector2f(cartWidth, cartHeight)));
		lanes = new std::vector<Lane*>();
		float cartPos = (laneWidth - cartWidth) / 2;
		cart->shape->move(cartPos, window->getSize().y - cartPos - cartWidth);

		for (int i = 0; i < lanesNum; i++) {
			Lane* lane = new Lane(new sf::Vector2f(laneWidth, window->getSize().y), cartPos + laneWidth * i);
			lane->sprite->move(laneWidth * lanes->size(), 0.0f);
			//switch (i)
			//{
			//case 0: lane->sprite->setFillColor(sf::Color::Green);
			//	break;
			//case 1: lane->sprite->setFillColor(sf::Color::Blue);
			//	break;
			//case 2: lane->shape->setFillColor(sf::Color::Red);
			//	break;
			//default:
			//	break;
			//}

			lanes->push_back(lane);
		}
	}

	void crash() {

	}
	
	void incrementScore(int value) {
		score += value;
	}

	void draw() {
		window->clear();
		auto windowSize = window->getSize();

		for (int i = 0; i < lanes->size(); i++) {
			auto lane = lanes->at(i);

			//Scroll lane texture
			lane->sprite->move(0.0f, 0.05f);
			if (lane->sprite->getPosition().y > 0) {
				lane->sprite->move(0.0f, ( - 1 * lane->sprite->getGlobalBounds().height / 2) + fmodf(windowSize.y, lane->sprite->getTexture()->getSize().y));
			}

			//Draw lane
			window->draw(*lane->sprite, sf::RenderStates::Default);

			//Draw obstacles
			for (int j = lane->obstacles->size() - 1; j > -1; j--) {
				auto obstacle = lane->obstacles->at(j);
				auto pos = scrollPosition - obstacle->position;
				if (pos > 0 && pos < window->getSize().y) {
					obstacle->shape->setPosition(lane->objectPosition, pos);
					window->draw(*obstacle->shape, sf::RenderStates::Default);
					if (cart->collision(obstacle)) {
						if (obstacle->colide(this)) {
							lane->obstacles->erase(lane->obstacles->begin() + j);
							delete obstacle;
						}
					}
				}
				if (pos > window->getSize().y) {
					lane->obstacles->erase(lane->obstacles->begin() + j);
					delete obstacle;
				}
			}
		}

		//Draw cart
		sf::Drawable* shape = cart->shape;
		window->draw(*shape, sf::RenderStates::Default);

		drawText();

		window->display();
	}

	//Draw text layer
	void drawText() {
		sf::Text text;
		text.setFont(*font);
		text.setString(std::to_string(score));
		text.setCharacterSize(24); // in pixels, not points!

		// set the color
		text.setFillColor(sf::Color::White);

		window->draw(text);

	}

	void moveCartLeft() {
		for (int i = lanes->size() - 1; i > -1; i--) {
			if (cart->shape->getPosition().x > lanes->at(i)->objectPosition) {
				cart->shape->setPosition(lanes->at(i)->objectPosition, cart->shape->getPosition().y);
				break;
			}
		}
	}

	void moveCartRight() {
		for (int i = 0; i < lanes->size(); i++) {
			if (cart->shape->getPosition().x < lanes->at(i)->objectPosition) {
				cart->shape->setPosition(lanes->at(i)->objectPosition, cart->shape->getPosition().y);
				break;
			}
		}
	}

	void scroll() {
		scrollPosition += 0.1f;
	}

	void addObstacle() {
		auto obstacle = new Trash();
		obstacle->position = scrollPosition + 60;
		lanes->at(0)->obstacles->push_back(obstacle);
	}

};

