#include "Wall.h"

Wall::Wall(GameDataRef data) : _data(data)
{
	wall.setTexture(&_data->assets.GetTexture("Wall Texture"));
}

void Wall::setPosandSize(float xPos, float yPos, float xSize, float ySize)
{
	wall.setPosition(xPos, yPos);
	wall.setSize(sf::Vector2f(xSize, ySize));
}
void Wall::Draw()
{
	_data->window.draw(wall);
}

sf::RectangleShape Wall::getSprite()
{
	return sf::RectangleShape();
}
