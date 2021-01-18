#include "GameState.h"

GameState::GameState(GameDataRef data) : _data(data)
{
}

void GameState::Init()
{
	_data->assets.LoadTexture("Player Texture", PLAYER_SPRITE);


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

		bulletVec[i].Fire(3);
	}
}

void GameState::Draw(float dt)
{
	_data->window.clear();

	player->DrawPlayer();

	for (int i = 0; i < bulletVec.size(); i++)
	{
		bulletVec[i].Draw();
	}

	_data->window.display();
}