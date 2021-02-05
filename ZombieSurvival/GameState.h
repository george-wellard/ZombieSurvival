#pragma once
#include <iostream>
#include "State.h"
#include "Game.h"
#include "Definitions.h"
#include "Player.h"
#include "Bullet.h"


class GameState : public State
{
public:

	GameState(GameDataRef data);

	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:

	GameDataRef _data;

	sf::Sprite background;

	sf::Event event;
	sf::Clock _clock;

	Player* player;
	std::vector<Bullet> bulletVec;

	bool isFiring = false;

	//Variables
	int mouseX = 0;
	int mouseY = 0;
};