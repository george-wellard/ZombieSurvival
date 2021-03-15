#include "GameState.h"

GameState::GameState(GameDataRef data) : _data(data)
{
}

void GameState::Init()
{
	_data->assets.LoadTexture("Player Texture", PLAYER_SPRITE);
	_data->assets.LoadTexture("Floor Texture", FLOOR_SPRITE);
	_data->assets.LoadTexture("Grass Texture", GRASS_SPRITE);
	_data->assets.LoadTexture("Zombie Texture", ZOMBIE_SPRITE);
	_data->assets.LoadTexture("Wall Texture", WALL_SPRITE);
	_data->assets.LoadTexture("Barracade Texture", BARRICADE_SPRITE);

	floor.setTexture(_data->assets.GetTexture("Floor Texture"));
	floor.setPosition(200, 200);
	floor.scale(sf::Vector2f(2, 1.1));

	grass.setTexture(_data->assets.GetTexture("Grass Texture"));
	grass.scale(sf::Vector2f(3, 3));
	
	Wall topWall1(_data); 
	Wall topWall2(_data);
	Wall rightWall1(_data);
	Wall rightWall2(_data);
	Wall leftWall1(_data);
	Wall leftWall2(_data);
	Wall bottomWall1(_data);
	Wall bottomWall2(_data);

	topWall1.setPosandSize(200, 200, 400, 25);
	topWall2.setPosandSize(800, 200, 400, 25);
	rightWall1.setPosandSize(1200, 200, 25, 550);

	leftWall1.setPosandSize(200, 200, 25, 550);

	bottomWall1.setPosandSize(200, 750, 400, 25);
	bottomWall2.setPosandSize(800, 750, 400, 25);

	wallVec.push_back(topWall1);
	wallVec.push_back(topWall2);
	wallVec.push_back(rightWall1);
	wallVec.push_back(rightWall2);
	wallVec.push_back(leftWall1);
	wallVec.push_back(leftWall2);
	wallVec.push_back(bottomWall1);
	wallVec.push_back(bottomWall2);

	Barracade topBarracade(_data);
	Barracade bottomBarracade(_data);

	topBarracade.setPos(600, 200);
	bottomBarracade.setPos(600, 750);

	barraVec.push_back(topBarracade);
	barraVec.push_back(bottomBarracade);

	ZombieSpawner spawn1();
	ZombieSpawner spawn2();

	player = new Player(_data);
}

void GameState::HandleInput()
{
	while (_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			_data->window.close();
		}

		if (sf::Event::KeyPressed)
		{
			player->MovePlayer(event);
		}

		if (event.type == sf::Event::MouseMoved)
		{
			mouseX = event.mouseMove.x;
			mouseY = event.mouseMove.y;

			const float PI = 3.14159265;

			float dX = mouseX - player->GetSprite().getPosition().x;
			float dY = mouseY - player->GetSprite().getPosition().y;

			float rotation = atan2(dY, dX);
			rotation *= 180 / PI;

			player->RotatePlayer(rotation);
		}

		if (sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
		{
			isFiring = true;
		}

	}
}

void GameState::Update(float dt)
{
	if (isFiring)
	{
		Bullet newBullet(_data);
		newBullet.setPos(player->GetSprite().getPosition().x, player->GetSprite().getPosition().y);
		bulletVec.push_back(newBullet);
		isFiring = false;
	}

	for (int i = 0; i < bulletVec.size(); i++)
	{
		mouseX = event.mouseMove.x;
		mouseY = event.mouseMove.y;

		const float PI = 3.14159265;

		float dX = mouseX - player->GetSprite().getPosition().x;
		float dY = mouseY - player->GetSprite().getPosition().y;

		float aim = atan2(dY, dX);
		aim *= 180 / PI;

		bulletVec[i].Fire(3, aim);
	}
}

void GameState::Draw(float dt)
{
	_data->window.clear();

	_data->window.draw(grass);

	_data->window.draw(floor);

	player->DrawPlayer();

	for (int i = 0; i < wallVec.size(); i++)
	{
		wallVec[i].Draw();
	}

	for (int i = 0; i < barraVec.size(); i++)
	{
		barraVec[i].Draw();
	}

	for (int i = 0; i < bulletVec.size(); i++)
	{
		bulletVec[i].Draw();
	}

	_data->window.display();
}