#pragma once

#include "Obstacle.h"

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
