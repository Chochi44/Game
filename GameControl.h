#pragma once
class GameControl
{
public:
	static const int TAKE = 0;
	static const int CRASH = 1;
	static const int LEVELUP = 2;

	virtual void crash() = 0;
	virtual void incrementScore(int value) = 0;
	virtual void playSound(int sound) = 0;
};

