#pragma once
#include "Game.h"
#include "Definitions.h"

class Zombie
{
public:

	Zombie(GameDataRef data);

	void Draw();

	void Move();

	sf::Sprite getSprite();

private:

	GameDataRef _data; 

	sf::Sprite zombie; 
};

