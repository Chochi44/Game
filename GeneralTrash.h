#pragma once
#include "Trash.h"
class GeneralTrash : public Trash
{
public:
	GeneralTrash(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_GENERAL_TRASH;
	}
};

