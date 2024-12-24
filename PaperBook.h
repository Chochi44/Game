#pragma once
#include "Trash.h"
class PaperBook :
    public Trash
{
public:
	PaperBook(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_PAPER_BOOK;
	}
};

