#pragma once

#include "Obstacle.h"
#include "Game.h"

class Pothole : public Obstacle
{
public:
    Pothole(GameControl* control) : Obstacle(control) {
        sound = GameControl::SOUND_CRASH;
        shape->setFillColor(sf::Color::Red);
    }

    bool colide() {
        playSound();
        control->crash();
        return false;
    }
};
