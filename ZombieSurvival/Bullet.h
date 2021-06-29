#pragma once
#include "Game.h"
#include "Definitions.h"

class Bullet
{
public: 

	sf::Vector2f currentVelocity;
	float maxSpeed = 15;

	Bullet(GameDataRef data);

	void setPos(float x, float y); 

	void Fire(sf::Vector2f speed);

	void Draw(); 

	const sf::CircleShape& getShape() const;

private:

	GameDataRef _data; 

	sf::CircleShape bullet; 
};

