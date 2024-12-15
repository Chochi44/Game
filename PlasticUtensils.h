#pragma once
#include "Trash.h"
class PlasticUtensils :
    public Trash
{
public:
	PlasticUtensils(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_PLASTIC_UTENSILS;
	}
};

