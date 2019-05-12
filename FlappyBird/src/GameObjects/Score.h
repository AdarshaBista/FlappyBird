#pragma once

#include <array>
#include <memory>

#include "Values/Values.h"
#include "Audio/Audio.h"
#include "GUI/Label.h"
#include "Engine/GameObject.h"
#include "Bird.h"
#include "Pipe.h"

class Score : public GameObject
{
private:
	std::shared_ptr<Bird> bird;
	std::array<std::shared_ptr<Pipe>, PIPE_NUM> pipes;

	std::unique_ptr<Label> scoreLabel;
	int score;

	std::shared_ptr<Audio> scoreSound;

public:
	Score(const std::shared_ptr<Bird>& bird, const std::array<std::shared_ptr<Pipe>, PIPE_NUM>& pipes, const std::shared_ptr<Audio>& scoreSound);

	virtual void handleEvents(const sf::Event& event) override;
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void reset() override;

};

