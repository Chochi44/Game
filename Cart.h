#pragma once
#include <SFML/Graphics.hpp>
#include "Obstacle.h"

class Cart
{
private:
	sf::Sprite sprite;
	sf::Texture* texture;
	GameControl* control;
public:

	Cart(GameControl* control)
	{
		this->control = control;
		texture = control->getTexture(GameControl::TEXTURE_CART);
		auto size = texture->getSize();
		sprite = sf::Sprite(*texture, sf::IntRect(0, 0, size.x, size.y));
	}

	void draw() {
		control->getWindow()->draw(sprite, sf::RenderStates::Default);
	}

	sf::FloatRect getBounds() {
		return sprite.getGlobalBounds();
	}

	int getWidth() {
		return texture->getSize().x;
	}

	int getHeight() {
		return texture->getSize().y;
	}
	
	void move(float offsetX, float offsetY) {
		sprite.move(offsetX, offsetY);
	}

	sf::Vector2f getPosition() {
		return sprite.getPosition();
	}

	void setPosition(float x, float y) {
		sprite.setPosition(x, y);
	}
};


