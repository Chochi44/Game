#pragma once
#include "Pothole.h"
class Bus :
	public Pothole
{
public:
	Bus(GameControl* control) : Pothole(control) {
		texture = GameControl::TEXTURE_BUS;
	}
};

