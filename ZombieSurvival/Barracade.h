#pragma once
#include "Game.h"
#include "Definitions.h"

class Barracade
{

public:

	Barracade(GameDataRef data);

	void setPos(float xPos, float yPos);

	void Draw();

	sf::Sprite getSprite();

private:

	GameDataRef _data;

	sf::Sprite barracade;

};

