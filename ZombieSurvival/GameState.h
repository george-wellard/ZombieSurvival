#pragma once
#include <iostream>
#include "State.h"
#include "Game.h"
#include "Definitions.h"
#include "Player.h"
#include "Bullet.h"
#include "Wall.h"
#include "Barracade.h"
#include "Zombie.h"
#include "ZombieSpawner.h"


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

	sf::Sprite floor;
	sf::Sprite grass;

	sf::Event event;
	sf::Clock _clock;

	Player* player;
	Wall* wall;
	Barracade* barracade;
	ZombieSpawner zombieSpawner;

	std::vector<Bullet> bulletVec;
	std::vector<Wall> wallVec;
	std::vector<Barracade> barraVec;
	std::vector <ZombieSpawner> spawnVec;
	

	bool isFiring = false;

	//Variables
	int mouseX = 0;
	int mouseY = 0;
};