#pragma once
#include "Trash.h"
class GlassCup : public Trash
{
public:
	GlassCup(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_GLASS_TRASH;
	}
};

