#pragma once
#include "Trash.h"

class PaperTrash : public Trash
{
public:
	PaperTrash	(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_BOX_TRASH;
	}
};

