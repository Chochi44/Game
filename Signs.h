#pragma once
#include "Pothole.h"
class Signs :
    public Pothole
{
public:
	Signs(GameControl* control) : Pothole(control) {
		texture = GameControl::TEXTURE_SIGN_1 + rand() % 4;
	}
};

