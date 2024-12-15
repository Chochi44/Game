#pragma once
#include "Trash.h"
class Apple : public Trash
{
public:
	Apple(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_GENERAL_APPLE;
	}
};

