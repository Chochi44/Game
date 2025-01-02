#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameControl.h"
#include "Cart.h"

//Base class for all course obstacles
class Obstacle
{
public:
	sf::Sprite* sprite;
	GameControl* control;

	float position;
	int sound = -1;
	int texture = -1;

	Obstacle(GameControl* control) {
		this->control = control;
		sprite = new sf::Sprite();
	}

	~Obstacle() {
		delete sprite;
	}

	virtual bool colide() = 0;

	virtual void missed() {

	}

	virtual void draw() {
		control->getWindow()->draw(*sprite, sf::RenderStates::Default);
	}

	virtual int getHeight() {
		return sprite->getLocalBounds().height;
	}

	virtual int getWidth() {
		return sprite->getLocalBounds().width;
	}

	virtual void setPosition(float x, float y) {
		sprite->setPosition(x, y);
	}

	virtual bool isComplex() {
		return false;
	}

	Obstacle* loadTexture() {
		if (texture > -1) {
			auto t = control->getTexture(texture);
			auto size = t->getSize();
			sprite->setTextureRect(sf::IntRect(0, 0, size.x, size.y));
			sprite->setTexture(*t);
			return this;
		}
	}

	void playSound() {
		if (sound > -1) {
			control->playSound(sound);
		}
	}

	virtual bool collision(Cart* cart)
	{
		return sprite->getGlobalBounds().intersects(cart->getBounds());
	}
};

