#pragma once

#include <memory>

#include "Window.h"
#include "ResourceHolder.h"

class ResourceHolder;

class Game
{
public:
	Window app;
	std::unique_ptr<ResourceHolder> res;

	enum State { MENU, RUNNING, GAMEOVER } currentState;

public:
	Game();
	void run();

	void handleEvents(const sf::Event& event);
	void update();
	void draw(sf::RenderWindow& window);

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

};

