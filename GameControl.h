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

	virtual void crash() = 0;
	virtual void incrementScore(int value) = 0;
	virtual void playSound(int sound) = 0;
	virtual sf::Texture* getTexture(int texture) = 0;
};

