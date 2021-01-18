#include "Bullet.h"

Bullet::Bullet(GameDataRef data) : _data(data)
{
	bullet.setSize(sf::Vector2f(10, 10));
	bullet.setFillColor(sf::Color::Blue);
}

void Bullet::setPos(float x, float y)
{
	bullet.setPosition(x, y);
}

void Bullet::Fire(int speed)
{
	bullet.move(speed, 0);
}

void Bullet::Draw()
{
	_data->window.draw(bullet);
}

const sf::RectangleShape& Bullet::getShape() const
{
	return bullet;
}
