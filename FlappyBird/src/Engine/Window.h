#pragma once

#include <SFML/Graphics.hpp>
#include "Values/Values.h"

class Window
{
private:
	sf::Image icon;
	sf::RenderWindow window;

public:
	Window();
	sf::RenderWindow& getWindow();

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
};

