#pragma once
#include "Game.h"
#include "Definitions.h"

class Bullet
{
public: 

	Bullet(GameDataRef data);

	void setPos(float x, float y); 

	void Fire(int speed, float aim);

	void Draw(); 

	const sf::CircleShape& getShape() const;

private:

	GameDataRef _data; 

	sf::CircleShape bullet; 
};

