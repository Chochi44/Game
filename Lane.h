#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Obstacle.h"

class Lane
{
public:
	sf::Sprite* sprite;
	sf::Texture corgi;
	

	int objectPosition;

	std::vector<Obstacle*>* obstacles;

	Lane(sf::Vector2f* vector, int objPos)
	{
		corgi.loadFromFile("lane.png");
		corgi.setRepeated(true);
		auto fRect = sf::FloatRect(0.0f, 0.0f, vector->x, vector->y * 2);
		auto iRect = sf::IntRect(fRect);
		sprite = new sf::Sprite(corgi, iRect);
		sprite->move(0.0f, -1 * vector->y);
		objectPosition = objPos;
		obstacles = new std::vector<Obstacle*>();
	}
};

