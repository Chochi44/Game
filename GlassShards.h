#pragma once
#include "Trash.h"
class GlassShards :
    public Trash
{
public:
	GlassShards(GameControl* control) : Trash(control) {
		texture = GameControl::TEXTURE_GLASS_SHARDS;
	}
};

