#pragma once
#include "Game.h"
#include "Definitions.h"

class Bullet
{
public: 

	Bullet(GameDataRef data);

	void setPos(float x, float y); 

	void Fire(int speed);

	void Draw(); 

	const sf::RectangleShape& getShape() const;

private:

	GameDataRef _data; 

	sf::RectangleShape bullet; 
};

