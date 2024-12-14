#pragma once
#include <SFML/Graphics.hpp>
#include "Obstacle.h"

class Cart
{
public:
	sf::Sprite sprite;
	sf::Texture* texture;

	Cart(GameControl* control)
	{
			texture = control->getTexture(GameControl::TEXTURE_CART);
			auto size = texture->getSize();
			sprite = sf::Sprite(*texture, sf::IntRect(0, 0, size.x, size.y));
	}

	bool collision(Obstacle* obstacle)
	{
		return sprite.getGlobalBounds().intersects(obstacle->sprite->getGlobalBounds());
	}

};


