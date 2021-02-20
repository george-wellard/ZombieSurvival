#include "Wall.h"

Wall::Wall(GameDataRef data)
{
	wall.setTexture(_data->assets.GetTexture("Wall Texture"));
}

void Wall::setPos(float x, float y)
{
	wall.setPosition(x, y);
}

void Wall::Draw()
{
	_data->window.draw(wall);
}

sf::Sprite Wall::getSprite()
{
	return sf::Sprite();
}
