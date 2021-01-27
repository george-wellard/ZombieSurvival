#include "Player.h"

Player::Player(GameDataRef data) : _data(data)
{
	player.setTexture(_data->assets.GetTexture("Player Texture"));

	player.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	player.setOrigin(player.getGlobalBounds().width / 2, player.getGlobalBounds().height / 2);
}

void Player::MovePlayer(sf::Event event)
{

	if (sf::Keyboard::Key::D == event.key.code)
	{
		player.move(30, 0);
	}

	if (sf::Keyboard::Key::A == event.key.code)
	{
		player.move(-30, 0);
	}

	if (sf::Keyboard::Key::W == event.key.code)
	{
		player.move(0, -30);
	}

	if (sf::Keyboard::Key::S == event.key.code)
	{
		player.move(0, 30);
	}
}

void Player::RotatePlayer(float rot)
{
	/*const float PI = 3.14159265;

	float dX = mousePos.x - player.getPosition().x;
	float dY = mousePos.y - player.getPosition().y;

	float rotation = atan2(dY, dX);
	rotation *= 180 / PI;*/

	player.setRotation(rot);
}

void Player::DrawPlayer()
{
	_data->window.draw(player);
}

const sf::Sprite& Player::GetSprite() const
{
	return player;
}
