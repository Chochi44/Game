#pragma once
#include "Trash.h"
class Diper :
    public Trash
{
public:
	Diper(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_GENERAL_DIPER;
	}
};

