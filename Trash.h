#pragma once

#include "Obstacle.h"
#include "Game.h"

class Trash : public Obstacle
{
public:
    Trash(GameControl* control) : Obstacle(control) {
        sound = GameControl::SOUND_TAKE;
    }

    bool colide() override {
        control->incrementScore(100);
        playSound();
        return true;
    }

    void missed() override {
        control->incrementScore(-50);
        control->playSound(GameControl::SOUND_MISSED);
    }
};

