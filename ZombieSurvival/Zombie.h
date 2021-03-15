#pragma once
#include "Game.h"
#include "Definitions.h"

class Zombie
{
public:

	Zombie(GameDataRef data);

	void Draw();

	void Movement();

	void MoveUp();

	void MoveDown();

	void MoveRight();

	void MoveLeft();

	sf::Sprite getSprite();

private:

	GameDataRef _data; 

	sf::Sprite zombie; 
};

