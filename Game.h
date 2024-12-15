#pragma once
#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "Lane.h"
#include "Cart.h"
#include "Trash.h"
#include "Pothole.h"
#include <list>
#include "PaperBox.h"
#include "GlassCup.h"
#include "PlasticToy.h"
#include "GeneralTrash.h"
#include "Apple.h"
#include "Diper.h"
#include "GlassBottle.h"
#include "GlassShards.h"
#include "PaperPiece.h"
#include "PlasticStraw.h"
#include "PlasticUtensils.h"
#include "StopSign.h"
#include "Car.h"


class Game : public GameControl
{
	Cart* cart;
	std::vector<Lane*>* lanes;
	std::vector<sf::Sound*>* sounds;
	std::vector<sf::Texture*>* textures;
	sf::RenderWindow* window;
	sf::Font* font;
	sf::RectangleShape* titleShape;
	sf::Text* gameOverText;
	std::vector<std::function<Obstacle* ()>>* obstacleTypes;

	float scrollPosition;

public:
	int score = 0;
	int level = 0;
	float velocity = 0.05f;
	float laneWidth = 60.0f;
	float cartWidth = 50.0f;
	float cartHeight = 50.0f;
	bool title = true;
	bool end = false;


	Game(int lanesNum, sf::RenderWindow* window)
	{
		initAssets();
		initObstacles();

		this->window = window;
		cart = new Cart(this);
		cartWidth = cart->texture->getSize().x;
		cartHeight = cart->texture->getSize().y;
		lanes = new std::vector<Lane*>();
		float cartPos = (laneWidth - cartWidth) / 2;

		auto laneTexture = GameControl::TEXTURE_LEFT_SIDE;
		auto lanePos = 0;
		for (int i = 0; i < lanesNum; i++) {
			auto lane = new Lane(getTexture(laneTexture));
			auto laneX = lane->texture->getSize().x;
			lane->objectPosition = lanePos + (laneX - cartWidth) / 2;
			lane->sprite->setTextureRect(sf::IntRect(0, 0, laneX, window->getSize().y * 2));
			lane->sprite->move(lanePos, 0.0f);

			lanePos += laneX;
			lanes->push_back(lane);
			laneTexture = i == lanesNum - 2 ? GameControl::TEXTURE_RIGHT_SIDE : GameControl::TEXTURE_LANE;
		}
		cart->sprite.move(lanes->at(0)->objectPosition, window->getSize().y - cartHeight);
	}

	void initAssets() {
		textures = new std::vector<sf::Texture*>();
		loadTexture("title.png");
		loadTexture("general truck.png");
		loadTexture("lane.png");
		loadTexture("leftside.png");
		loadTexture("rightside.png");
		loadTexture("paper box.png");
		loadTexture("hole.png");
		loadTexture("glass cup.png");
		loadTexture("plastic toy.png");
		loadTexture("general trash.png");
		loadTexture("general apple.png");
		loadTexture("general diper.png");
		loadTexture("glass bottle.png");
		loadTexture("glass shards.png");
		loadTexture("paper piece.png");
		loadTexture("plastic straw.png");
		loadTexture("plastic utensils.png");
		loadTexture("stop sign.png");
		loadTexture("car.png");

		sounds = new std::vector<sf::Sound*>();
		loadSound("take.wav");
		loadSound("crash.wav");
		loadSound("levelup.wav");

		//Load font
		font = new sf::Font();
		if (!font->loadFromFile("tuffy.ttf"))
		{
			std::cout << "Font not found!";
			window->close();
		}

		titleShape = new sf::RectangleShape();
		titleShape->setTexture(textures->at(GameControl::TEXTURE_TITLE));

		gameOverText = new sf::Text();
		gameOverText->setFont(*font);
		gameOverText->setCharacterSize(50);
		gameOverText->setOutlineColor(sf::Color::Yellow);
		gameOverText->setFillColor(sf::Color::Red);
		gameOverText->setOutlineThickness(3);
		gameOverText->setString("GAME OVER!!!");
	}

	void initObstacles() {
		obstacleTypes = new std::vector<std::function<Obstacle * ()>>();
		obstacleTypes->push_back([&] {return (new Pothole(this))->loadTexture(); });
		obstacleTypes->push_back([&] {return (new PaperBox(this))->loadTexture(); });
		obstacleTypes->push_back([&] {return (new GlassCup(this))->loadTexture(); });
		obstacleTypes->push_back([&] {return (new PlasticToy(this))->loadTexture(); });
		obstacleTypes->push_back([&] {return (new GeneralTrash(this))->loadTexture(); });
		obstacleTypes->push_back([&] {return (new Apple(this))->loadTexture(); });
		obstacleTypes->push_back([&] {return (new Diper(this))->loadTexture(); });
		obstacleTypes->push_back([&] {return (new GlassBottle(this))->loadTexture(); });
		obstacleTypes->push_back([&] {return (new GlassShards(this))->loadTexture(); });
		obstacleTypes->push_back([&] {return (new PaperPiece(this))->loadTexture(); });
		obstacleTypes->push_back([&] {return (new PlasticStraw(this))->loadTexture(); });
		obstacleTypes->push_back([&] {return (new PlasticUtensils(this))->loadTexture(); });
		obstacleTypes->push_back([&] {return (new StopSign(this))->loadTexture(); });
		obstacleTypes->push_back([&] {return (new Car(this))->loadTexture(); });
	}

	void loadTexture(const std::string& filename) {
		auto texture = new sf::Texture();
		if (!texture->loadFromFile(filename)) {
			std::cout << filename << " not found";
			textures->push_back(0);
		}
		else {
			textures->push_back(texture);
		}
	}


	void loadSound(const std::string& filename) {
		auto buffer = new sf::SoundBuffer();

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
		end = true;
	}

	void incrementScore(int value) {
		score += value;
	}

	void draw() {
		window->clear();
		auto windowSize = window->getSize();

		for (int i = 0; i < lanes->size(); i++) {
			auto lane = lanes->at(i);

			if (!end) {
				//Scroll lane texture
				lane->sprite->move(0.0f, velocity);
				if (lane->sprite->getPosition().y > 0) {
					lane->sprite->move(0.0f, (-1 * lane->sprite->getGlobalBounds().height / 2) + fmodf(windowSize.y, lane->sprite->getTexture()->getSize().y));
				}
			}

			//Draw lane
			window->draw(*lane->sprite, sf::RenderStates::Default);

			//Draw obstacles
			for (int j = lane->obstacles->size() - 1; j > -1; j--) {
				auto obstacle = lane->obstacles->at(j);
				auto pos = scrollPosition - obstacle->position;
				if (pos > 0 && pos < window->getSize().y) {
					obstacle->sprite->setPosition(lane->objectPosition, pos);
					window->draw(*obstacle->sprite, sf::RenderStates::Default);
					if (!end && cart->collision(obstacle)) {
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
		window->draw(cart->sprite, sf::RenderStates::Default);

		drawText();

		window->display();
	}

	//Draw text layer
	void drawText() {
		auto size = window->getSize();
		sf::Text text;
		text.setFont(*font);
		text.setString("Level: " + std::to_string(level) + " Score: " + std::to_string(score));
		text.setCharacterSize(24); // in pixels, not points!

		// set the color
		text.setFillColor(sf::Color::White);
		auto bounds = text.getLocalBounds();
		text.setPosition(size.x - bounds.width - 5.0f, 5.0f);

		window->draw(text);

		if (end) {
			auto bounds = gameOverText->getLocalBounds();
			gameOverText->setPosition((size.x - bounds.width) / 2, (size.y - bounds.height) / 2);
			window->draw(*gameOverText);
		}

	}

	void moveCartLeft() {
		for (int i = lanes->size() - 1; i > -1; i--) {
			if (cart->sprite.getPosition().x > lanes->at(i)->objectPosition) {
				cart->sprite.setPosition(lanes->at(i)->objectPosition, cart->sprite.getPosition().y);
				break;
			}
		}
	}

	void moveCartRight() {
		for (int i = 0; i < lanes->size(); i++) {
			if (cart->sprite.getPosition().x < lanes->at(i)->objectPosition) {
				cart->sprite.setPosition(lanes->at(i)->objectPosition, cart->sprite.getPosition().y);
				break;
			}
		}
	}

	void scroll() {
		scrollPosition += velocity;
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
		playSound(SOUND_LEVELUP);
		generateLevel();
		velocity += 0.02f;
	}

	void generateLevel() {
		auto levelPos = 0;
		auto remObstacles = level * 5;
		for (auto i = 0; i < remObstacles; i++) {
			auto obstacle = obstacleTypes->at(rand() % obstacleTypes->size())();
			obstacle->position = scrollPosition + levelPos;
			lanes->at(rand() % lanes->size())->obstacles->push_back(obstacle);
			levelPos += obstacle->sprite->getLocalBounds().height + cartHeight + rand() % 500;
		}
	}

	void drawTitle() {
		auto size = window->getSize();
		titleShape->setSize(sf::Vector2f(size.x, size.y));
		window->draw(*titleShape);
		window->display();
	}

	void start() {
		score = 0;
		level = 0;
		title = false;
		end = false;
		velocity = 0.05f;
		for (auto lane : *lanes) {
			lane->obstacles->clear();
		}
	}

	sf::Texture* getTexture(int texture) {
		return textures->at(texture);
	}

};

