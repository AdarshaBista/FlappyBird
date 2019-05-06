#pragma once

#include <memory>
#include <functional>
#include <SFML/Graphics.hpp>

#include "Audio/Audio.h"
#include "Widget.h"

class IconButton : public Widget
{
private:
	sf::Texture iconTex;
	sf::Sprite icon;
	
	std::function<void()> onPressed;
	std::shared_ptr<Audio> clickSound;

private:
	virtual void setPosition(const sf::Vector2f& pos) override;
	virtual void setScale(const sf::Vector2f& factor) override;
	virtual void setColor(const sf::Color& color) override;

	bool isClicked(const sf::RenderWindow& window, const sf::Event& event);
	bool isHovering(const sf::RenderWindow& window);
	void animate(const sf::RenderWindow& window);

public:
	IconButton(const std::string& iconPath, const sf::Vector2f& pos, std::shared_ptr<Audio> clickSound);
	void setCallback(std::function<void()> onPressedCallback);

	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& event) override;
	virtual void update(const sf::RenderWindow& window) override;
	virtual void draw(sf::RenderWindow& window) override;

};

