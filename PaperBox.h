#pragma once
#include "Trash.h"

class PaperBox : public Trash
{
public:
	PaperBox(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_PAPER_BOX;
	}
};

