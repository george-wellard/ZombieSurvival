#include "Barracade.h"

Barracade::Barracade(GameDataRef data) : _data(data)
{
	barracade.setTexture(_data->assets.GetTexture("Barracade Texture"));
	barracade.setScale(sf::Vector2f(2, 1));
}

void Barracade::setPos(float xPos, float yPos)
{
	barracade.setPosition(xPos, yPos);
}

void Barracade::Draw()
{
	_data->window.draw(barracade);
}

sf::Sprite Barracade::getSprite()
{
	return sf::Sprite();
}
