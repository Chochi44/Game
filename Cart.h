#pragma once
#include <SFML/Graphics.hpp>
#include "Obstacle.h"

class Cart
{
public:
	sf::Shape* shape;
	sf::Shape* obstacle;

	Cart(sf::Shape* shape)
	{
		this->shape = shape;
	}

	bool collision(Obstacle* obstacle)
	{
		return shape->getGlobalBounds().intersects(obstacle->shape->getGlobalBounds());
	}

};


