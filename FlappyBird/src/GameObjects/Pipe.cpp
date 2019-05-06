#include "Pipe.h"


Pipe::Pipe(int offset) : maxOscillationSpeed(1.5f), oscillationSpeed(0.0f), posOffset(offset),
						oscillationAcc(0.05f), oscillationDir(1), hasPassed(false), speed(3.0f),
						xDistBetweenPipes(350.0f), yDistBetweenPipes(320.0f)
{
	// Load and assign textures
	pipeTexture.loadFromFile(PIPE_PATH);
	pipes.first.setTexture(pipeTexture);
	pipes.second.setTexture(pipeTexture);

	// Flip first(top) pipe
	pipes.first.setScale(1.0f, -1.0f);

	// Set pipes color
	pipes.first.setColor(sf::Color(10, 10, 100, 200));
	pipes.second.setColor(sf::Color(10, 10, 100, 200));

	// Set first(top) and second(bottom) pipe direction to -1(Opposite) or 1(Same)
	std::array<int, 2> pipeDirOptions = { -1, 1 };
	oscillationModes.first = pipeDirOptions[rand() % 2];
	oscillationModes.second = pipeDirOptions[rand() % 2];

	// Set Pipe Positions
	float yPos = rand() % 150 + 200.0f;
	pipes.first.setPosition(WIDTH + xDistBetweenPipes * posOffset, yPos);
	pipes.second.setPosition(WIDTH + xDistBetweenPipes * posOffset, yPos + yDistBetweenPipes);

}

const std::pair<sf::Sprite, sf::Sprite>& Pipe::getPipes()
{
	return pipes;
}

void Pipe::handleEvents(const sf::Event & event)
{
}

void Pipe::update()
{
	speed += 0.0005f;

	// Move Pipes up and Down
	oscillationSpeed += oscillationAcc * oscillationDir;
	if (oscillationSpeed > maxOscillationSpeed || oscillationSpeed < -maxOscillationSpeed)
	{
		oscillationSpeed = maxOscillationSpeed * oscillationDir;
		oscillationDir = -oscillationDir;
	}

	pipes.first.move(-speed, oscillationSpeed * oscillationModes.first);
	pipes.second.move(-speed, oscillationSpeed * oscillationModes.second);

	// Wrap Pipes
	if (pipes.first.getPosition().x + pipes.first.getLocalBounds().width < 0.0f)
	{
		hasPassed = false;

		// Set New Positions
		float yPos = rand() % 150 + 200.0f;
		pipes.first.setPosition(WIDTH + xDistBetweenPipes, yPos);
		pipes.second.setPosition(WIDTH + xDistBetweenPipes, yPos + yDistBetweenPipes);
	}
}

void Pipe::draw(sf::RenderWindow & window)
{
	window.draw(pipes.first);
	window.draw(pipes.second);
}

void Pipe::reset()
{
	speed = 3.0f;

	float yPos = rand() % 150 + 200.0f;
	pipes.first.setPosition(WIDTH + xDistBetweenPipes * posOffset, yPos);
	pipes.second.setPosition(WIDTH + xDistBetweenPipes * posOffset, yPos + yDistBetweenPipes);
}
