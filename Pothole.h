#pragma once

#include "Obstacle.h"

//Base class for all course game ending obstacles
class Pothole : public Obstacle
{
public:
    Pothole(GameControl* control) : Obstacle(control) {
        sound = GameControl::SOUND_CRASH;
        texture = GameControl::TEXTURE_POTHOLE;
    }

    bool colide() override {
        playSound();
        control->crash();
        return false;
    }
};
