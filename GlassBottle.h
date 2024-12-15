#pragma once
#include "Trash.h"
class GlassBottle :
    public Trash
{
public:
	GlassBottle(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_GLASS_BOTTLE;
	}
};

