#pragma once

#include <SFML/Graphics.hpp>
#include "Values/Values.h"
#include "Widget.h"

class Label : public Widget
{
private:
	sf::Font font;
	sf::Text label;

private:
	virtual void setPosition(const sf::Vector2f& pos) override;
	virtual void setScale(const sf::Vector2f& factor) override;
	virtual void setColor(const sf::Color& color) override;

public:
	Label(const std::string& labelStr, const sf::Vector2f& pos, int charSize);
	void setLabel(const std::string& newLabel);

	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& event) override;
	virtual void update(const sf::RenderWindow& window) override;
	virtual void draw(sf::RenderWindow& window) override;

};

