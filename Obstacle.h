#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameControl.h"

class Obstacle
{
public:
	sf::Shape* shape;
	GameControl* control;

	float position;
	int sound = -1;

	Obstacle(GameControl* control) {
		this->control = control;
		shape = new sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
		shape->setFillColor(sf::Color::Black);
	}

	~Obstacle() {
		delete shape;
	}

	virtual bool colide() = 0;

	void playSound() {
		if (sound > -1) {
			control->playSound(sound);
		}
	}
};

