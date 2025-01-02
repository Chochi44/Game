#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Obstacle.h"

class Lane
{
public:
	sf::Sprite* sprite;
	sf::Texture* texture;

	int objectPosition;

	std::vector<Obstacle*>* obstacles;

	Lane(sf::Texture* texture)
	{
		this->texture = texture;
		texture->setRepeated(true);
		sprite = new sf::Sprite(*texture);
		obstacles = new std::vector<Obstacle*>();
	}
};

