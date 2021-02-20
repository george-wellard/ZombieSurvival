#pragma once
#include "Definitions.h"
#include "Game.h"

class Wall
{
public:

	Wall(GameDataRef data);

	void setPos(float x, float y);

	void Draw();

	sf::Sprite getSprite(); 

private:

	GameDataRef _data;

	sf::Sprite wall; 
};

