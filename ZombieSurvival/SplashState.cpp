#include "SplashState.h"
#include "Definitions.h"
#include "GameState.h"

#include<iostream>
#include<sstream>

SplashState::SplashState(GameDataRef data) : _data(data)
{

}

void SplashState::Init()
{
	_data->assets.LoadTexture("Splash State Background", SPLASH_SCREEN_BACKGROUND_FILEPATH);

	_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));

	_background.setPosition((SCREEN_WIDTH / 2) - (_background.getGlobalBounds().width / 2),
		((SCREEN_HEIGHT / 2) - (_background.getGlobalBounds().height / 2)));
}

void SplashState::HandleInput()
{
	sf::Event event;

	while (_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			_data->window.close();
		}
	}
}

void SplashState::Update(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		_data->machine.AddState(StateRef(new GameState(_data)), true);
	}
}

void SplashState::Draw(float dt)
{
	_data->window.clear();

	_data->window.draw(_background);

	_data->window.display();
}