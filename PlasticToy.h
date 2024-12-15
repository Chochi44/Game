#pragma once
#include "Trash.h"
class PlasticToy : public Trash
{
public:
	PlasticToy(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_PLASTIC_TOY;
	}
};

