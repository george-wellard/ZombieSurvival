#pragma once
#include "Game.h"
#include "Definitions.h"
#include "ZombiePos.h"

class Zombie
{
public:

	Zombie(GameDataRef data);

	void Draw();

	void Movement();

	void MoveForward();

	void MoveBackwards();

	void MoveRight();

	void MoveLeft();

	void Stop();

	float getX() const { return currentPos.getX(); } // Getting the current positions which are stored in Enemy Pos

	float getY() const { return currentPos.getY(); }

	float getRo() const { return currentPos.getRo(); }

	ZombiePos currentPos;

	sf::Sprite getSprite();

	void clearMovement();

	float newX;
	float newY;
	float newRo;

private:

	GameDataRef _data;
	sf::Sprite zombie; 
	float pX;
	float pY;

	float speed;

protected:

	bool forward = false;
	bool backward = false;
	bool right = false;
	bool left = false;
};

