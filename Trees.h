#pragma once
#include "Pothole.h"
class Trees :
    public Pothole
{
public:
	Trees(GameControl* control) : Pothole(control) {
		texture = GameControl::TEXTURE_TREE_1 + rand() % 3;
	}
};

