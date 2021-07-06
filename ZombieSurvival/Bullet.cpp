#include "Bullet.h"

Bullet::Bullet(GameDataRef data) : _data(data) 
{
	bullet.setRadius(10);
	bullet.setFillColor(sf::Color::Blue);
}

void Bullet::setPos(sf::Vector2f pos)
{
	bullet.setPosition(pos);
}

void Bullet::Fire(sf::Vector2f speed)
{
	bullet.move(speed);
}

void Bullet::Draw()
{
	_data->window.draw(bullet);
}

const sf::CircleShape& Bullet::getShape() const
{
	return bullet;
}
