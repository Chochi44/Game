#pragma once

#include "Obstacle.h"
#include "Game.h"

class Trash : public Obstacle
{
public:
    Trash() : Obstacle() {

    }

    bool colide(GameControl* control) {
        control->incrementScore(100);
        return true;
    }
};

