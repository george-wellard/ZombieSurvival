#include "Bullet.h"

Bullet::Bullet(GameDataRef data) : _data(data)
{
	bullet.setRadius(10);
	bullet.setFillColor(sf::Color::Blue);
}

void Bullet::setPos(float x, float y)
{
	bullet.setPosition(x, y);
}

void Bullet::Fire(int speed, float aim)
{
	bullet.move(speed, 0);
}

void Bullet::Draw()
{
	_data->window.draw(bullet);
}

const sf::CircleShape& Bullet::getShape() const
{
	return bullet;
}
