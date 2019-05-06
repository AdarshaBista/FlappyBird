#include "Score.h"


Score::Score(std::shared_ptr<Bird> bird, std::array<std::shared_ptr<Pipe>, PIPE_NUM> pipes, std::shared_ptr<Audio> scoreSound)
	: bird(bird), pipes(pipes), scoreSound(scoreSound), score(0)
{
	scoreLabel = std::make_unique<Label>(std::to_string(score), sf::Vector2f(WIDTH / 2.0f, HEIGHT / 10.0f), 64);
}

void Score::handleEvents(const sf::Event& event)
{
}

void Score::update()
{
	for (auto& pipe : pipes)
	{
		if (!pipe->hasPassed && (bird->getPosition().x > pipe->getPipes().first.getPosition().x +
			pipe->getPipes().first.getGlobalBounds().width))
		{
			scoreSound->play();
			pipe->hasPassed = true;
			score++;
			scoreLabel->setLabel(std::to_string(score));
		}
	}
}

void Score::draw(sf::RenderWindow& window)
{
	scoreLabel->draw(window);
}

void Score::reset()
{
	score = 0;
	scoreLabel->setLabel("0");
}