#pragma once
#include "Definitions.h"
#include "Game.h"

class Wall
{
public:

	Wall(GameDataRef data);

	void setPosandSize(float xPos, float yPos, float xSize, float ySize);

	void Draw();

	sf::RectangleShape getSprite(); 

private:

	GameDataRef _data;

	sf::RectangleShape wall; 
};

