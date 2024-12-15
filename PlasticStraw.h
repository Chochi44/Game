#pragma once
#include "Trash.h"
class PlasticStraw :
    public Trash
{
public:
	PlasticStraw(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_PLASTIC_STRAW;
	}

};

