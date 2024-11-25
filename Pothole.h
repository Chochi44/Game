#pragma once

#include "Obstacle.h"
#include "Game.h"

class Pothole : public Obstacle
{
public:
    Pothole(GameControl* control) : Obstacle(control) {
        sound = GameControl::CRASH;
        shape->setFillColor(sf::Color::Red);
    }

    bool colide() {
        control->crash();
        playSound();
        return false;
    }
};
