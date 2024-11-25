#pragma once
#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "Lane.h"
#include "Cart.h"
#include "Trash.h"
#include "Pothole.h"
#include <list>

class Game : public GameControl
{
	Cart* cart;
	std::vector<Lane*>* lanes;
	std::vector<sf::Sound*>* sounds;
	sf::RenderWindow* window;
	sf::Font* font;
	std::vector<std::function<Obstacle*()>>* obstacleTypes;

	float scrollPosition;

public:
	int score = 0;
	int level = 0;
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

		initSounds();
		initObstacles();

		this->window = window;
		cart = new Cart(new sf::RectangleShape(sf::Vector2f(cartWidth, cartHeight)));
		lanes = new std::vector<Lane*>();
		float cartPos = (laneWidth - cartWidth) / 2;
		cart->shape->move(cartPos, window->getSize().y - cartPos - cartWidth);

		for (int i = 0; i < lanesNum; i++) {
			Lane* lane = new Lane(new sf::Vector2f(laneWidth, window->getSize().y), cartPos + laneWidth * i);
			lane->sprite->move(laneWidth * lanes->size(), 0.0f);
			lanes->push_back(lane);
		}
	}

	void initSounds() {
		sounds = new std::vector<sf::Sound*>();
		loadSound("take.wav");
		loadSound("crash.wav");
	}

	void initObstacles() {
		obstacleTypes = new std::vector<std::function<Obstacle * ()>>();
		obstacleTypes->push_back([&] {return new Trash(this); });
		obstacleTypes->push_back([&] {return new Pothole(this); });
	}

	void loadSound(const std::string& filename) {
		sf::SoundBuffer* buffer = new sf::SoundBuffer();

		if (!buffer->loadFromFile(filename)) {
			std::cout << filename << " not found!";
			sounds->push_back(0);
		}
		else {
			sf::Sound* sound = new sf::Sound(*buffer);
			sounds->push_back(sound);
		}
	}

	void playSound(int sound) {
		auto s = sounds->at(sound);
		if (s) {
			s->play();
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
						if (obstacle->colide()) {
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
		text.setString("Level: " + std::to_string(level) + " Score: " + std::to_string(score));
		text.setCharacterSize(24); // in pixels, not points!

		// set the color
		text.setFillColor(sf::Color::White);
		auto bounds = text.getLocalBounds();
		text.setPosition(window->getSize().x - bounds.width - 5.0f, 5.0f);

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

	void checkLevel() {
		int rem = 0;
		for (auto lane : *lanes) {
			rem += lane->obstacles->size();
		}

		if (rem == 0) {
			levelUp();
		}
	}

	void levelUp() {
		level++;
		generateLevel();
	}

	void generateLevel() {
		auto levelPos = 0;
		auto remObstacles = level * 5;
		for (auto i = 0; i < remObstacles; i++) {
			auto obstacle = obstacleTypes->at(rand() % obstacleTypes->size())();
			obstacle->position = scrollPosition + levelPos;
			lanes->at(rand() % lanes->size())->obstacles->push_back(obstacle);
			levelPos += obstacle->shape->getLocalBounds().height + cartHeight + rand() % 500;
		}
	}

	void addObstacle() {
		srand(time(0));
		auto obstacle = obstacleTypes->at(rand() % obstacleTypes->size())();
		obstacle->position = scrollPosition + 60;
		lanes->at(0)->obstacles->push_back(obstacle);
	}

};

