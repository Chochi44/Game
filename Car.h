#pragma once
#include "Pothole.h"
class Car :
    public Pothole
{
public:
	Car(GameControl* control) : Pothole(control) {
		texture = GameControl::TEXTURE_CAR;
	}
};

