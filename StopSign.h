#pragma once
#include "Pothole.h"
class StopSign :
    public Pothole
{
public:
	StopSign(GameControl* control) : Pothole(control) {
		texture = GameControl::TEXTURE_STOP_SIGN;
	}
};

