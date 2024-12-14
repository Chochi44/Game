#pragma once
#include "Trash.h"
class GlassTrash : public Trash
{
public:
	GlassTrash(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_GLASS_TRASH;
	}
};

