#pragma once
#include "Trash.h"
class PaperPiece :
    public Trash
{
public:
	PaperPiece(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_PAPER_PIECE;
	}
};

