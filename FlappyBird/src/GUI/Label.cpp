#include "Label.h"


Label::Label(const std::string& labelStr, const sf::Vector2f& pos, int charSize)
{
	// Load text
	font.loadFromFile(FONT_PATH);
	label.setFont(font);
	label.setCharacterSize(charSize);
	label.setFillColor(sf::Color::White);
	label.setString(labelStr);


	// Set center of label as origin
	label.setOrigin(label.getGlobalBounds().width / 2.0f + label.getGlobalBounds().left,
					label.getGlobalBounds().height / 2.0f + label.getGlobalBounds().top);
	label.setPosition(pos);
}

void Label::setLabel(const std::string& newLabel)
{
	label.setString(newLabel);
}

void Label::setPosition(const sf::Vector2f& pos)
{
	label.setPosition(pos);
}

void Label::setScale(const sf::Vector2f& factor)
{
	label.setScale(factor);
}

void Label::setColor(const sf::Color& color)
{
	label.setFillColor(color);
}

void Label::handleEvents(const sf::RenderWindow& window, const sf::Event& event)
{
}

void Label::update(const sf::RenderWindow& window)
{
}

void Label::draw(sf::RenderWindow& window)
{
	window.draw(label);
}
