#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameControl.h"

class Obstacle
{
public:
	sf::Shape* shape;

	float position;

	Obstacle() {
		shape = new sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
		shape->setFillColor(sf::Color::Black);
	}

	~Obstacle() {
		delete shape;
	}

	virtual bool colide(GameControl* control) = 0;
};

