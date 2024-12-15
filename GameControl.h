#pragma once
class GameControl
{
public:
	static const int SOUND_TAKE = 0;
	static const int SOUND_CRASH = 1;
	static const int SOUND_LEVELUP = 2;

	static const int TEXTURE_TITLE = 0;
	static const int TEXTURE_CART = 1;
	static const int TEXTURE_LANE = 2;
	static const int TEXTURE_LEFT_SIDE = 3;
	static const int TEXTURE_RIGHT_SIDE = 4;
	static const int TEXTURE_PAPER_BOX = 5;
	static const int TEXTURE_POTHOLE = 6;
	static const int TEXTURE_GLASS_TRASH = 7;
	static const int TEXTURE_PLASTIC_TOY = 8;
	static const int TEXTURE_GENERAL_TRASH = 9;
	static const int TEXTURE_GENERAL_APPLE = 10;
	static const int TEXTURE_GENERAL_DIPER = 11;
	static const int TEXTURE_GLASS_BOTTLE = 12;
	static const int TEXTURE_GLASS_SHARDS = 13;
	static const int TEXTURE_PAPER_PIECE = 14;
	static const int TEXTURE_PLASTIC_STRAW = 15;
	static const int TEXTURE_PLASTIC_UTENSILS = 16;

	virtual void crash() = 0;
	virtual void incrementScore(int value) = 0;
	virtual void playSound(int sound) = 0;
	virtual sf::Texture* getTexture(int texture) = 0;
};

