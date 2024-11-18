#pragma once
class GameControl
{
public:
	virtual void crash() = 0;
	virtual void incrementScore(int value) = 0;
};

