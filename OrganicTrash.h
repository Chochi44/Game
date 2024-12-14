#pragma once
#include "Trash.h"
class OrganicTrash : public Trash
{
public:
	OrganicTrash(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_ORGANIC_TRASH;
	}
};

