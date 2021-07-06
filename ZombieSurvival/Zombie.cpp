#include "Zombie.h"

Zombie::Zombie(GameDataRef data) : _data(data)
{
	zombie.setTexture(_data->assets.GetTexture("Zombie Texture"));

	zombie.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	zombie.setOrigin(zombie.getGlobalBounds().width / 2, zombie.getGlobalBounds().height / 2);
}

void Zombie::Draw()
{
	_data->window.draw(zombie);
}

void Zombie::Movement()
{
}

void Zombie::MoveForward()
{
	clearMovement();
	forward = true;
}

void Zombie::MoveBackwards()
{
	clearMovement();
	backward = true;
}

void Zombie::MoveRight()
{
	clearMovement();
	right = true;
}

void Zombie::MoveLeft()
{
	clearMovement();
	left = true;
}

void Zombie::Stop()
{
	clearMovement();
}

sf::Sprite Zombie::getSprite()
{
	return sf::Sprite();
}

void Zombie::clearMovement()
{
	forward = false;
	backward = false;
	right = false;
	left = false;
}
