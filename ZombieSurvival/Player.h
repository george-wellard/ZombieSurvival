#pragma once
#include "Game.h"
#include "Definitions.h"

class Player
{
public:

	Player(GameDataRef data); 

	void MovePlayer(sf::Event event);

	void RotatePlayer(float rot);

	void DrawPlayer();

	const sf::Sprite& GetSprite() const;

private:

	GameDataRef _data;

	sf::Sprite player;
};

