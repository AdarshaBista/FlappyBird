#pragma once

#include <SFML/Graphics.hpp>

class Widget
{
private:
	struct Animation
	{
	private:
		sf::Vector2f scaleFactor;
		float maxScale;
		float speed;
		sf::Color coverColor;

	public:
		Animation();
		void enlarge(Widget* widget);
		void cover(Widget* widget);

		void resetEnlarge(Widget* widget);
		void resetCover(Widget* widget);

	};

protected:
	Animation anim;

private:
	virtual void setPosition(const sf::Vector2f& pos) = 0;
	virtual void setScale(const sf::Vector2f& factor) = 0;
	virtual void setColor(const sf::Color& color) = 0;

public:
	Widget();

	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& event) = 0;
	virtual void update(const sf::RenderWindow& window) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

};

