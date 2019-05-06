#pragma once

#include <array>
#include <SFML/Graphics.hpp>

#include "Values/Values.h"
#include "Engine/GameObject.h"

class Pipe : public GameObject
{
private:
	sf::Texture pipeTexture;
	std::pair<sf::Sprite, sf::Sprite> pipes;
	std::pair<int, int> oscillationModes;

	const float maxOscillationSpeed;
	const float oscillationAcc;
	float oscillationSpeed;
	int oscillationDir;
	
	const int posOffset;
	float speed;

	const float xDistBetweenPipes;
	const float yDistBetweenPipes;

public:
	bool hasPassed;

public:
	Pipe(int offset);
	const std::pair<sf::Sprite, sf::Sprite>& getPipes();

	virtual void handleEvents(const sf::Event& event) override;
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void reset() override;

};