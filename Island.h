#pragma once
#include "Pothole.h"

//Complex obstacle build by multiple sprites
class Island :
    public Pothole
{
public:
	std::vector<sf::Sprite*> sprites;
	int height = 0;

	Island(GameControl* control) : Pothole(control) {
		auto len = rand() % 4;

		sprites = std::vector<sf::Sprite*>();
		sprites.push_back(new sf::Sprite(*control->getTexture(GameControl::TEXTURE_TOP_ISLAND)));
		height = sprites.back()->getLocalBounds().height;
		for (int i = 0; i <= len; i++) {
			sprites.push_back(new sf::Sprite(*control->getTexture(GameControl::TEXTURE_MIDDLE_ISLAND)));
			height += sprites.back()->getLocalBounds().height;
		}
		sprites.push_back(new sf::Sprite(*control->getTexture(GameControl::TEXTURE_BOTTOM_ISLAND)));
		height += sprites.back()->getLocalBounds().height;
	}

	int getHeight() override {
		return height;
	}

	int getWidth() override {
		return sprites.at(0)->getLocalBounds().width;
	}

	void draw() override {
		for (auto sprite : sprites) {
			control->getWindow()->draw(*sprite, sf::RenderStates::Default);
		}
	}

	void setPosition(float x, float y) override {
		for (auto sprite : sprites) {
			sprite->setPosition(x, y);
			y += sprite->getLocalBounds().height;
		}
	}

	bool collision(Cart* cart) override
	{
		for (auto sprite : sprites) {
			if (sprite->getGlobalBounds().intersects(cart->getBounds())) {
				return true;
			}
		}
		return false;
	}

	bool isComplex() override {
		return true;
	}
};

