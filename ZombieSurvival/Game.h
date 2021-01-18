#pragma once

#include<string>
#include<SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

struct GameData
{
	StateMachine machine;
	sf::RenderWindow window;
	AssetManager assets;
	InputManager input;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
public:

	Game(int width, int height, std::string title);

	void Run();

private:

	sf::RenderWindow* window;

	const float dt = 1.0f / 60.0f;
	sf::Clock clock;
	GameDataRef _data = std::make_shared<GameData>();

};