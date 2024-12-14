#pragma once
#include "Trash.h"
class PlasticTrash : public Trash
{
public:
	PlasticTrash(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_PLASTIC_TRASH;
	}
};

