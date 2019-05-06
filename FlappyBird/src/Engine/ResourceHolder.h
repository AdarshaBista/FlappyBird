#pragma once

#include <map>
#include <array>
#include <memory>

#include "Values/Values.h"
#include "Game.h"

#include "GameObject.h"
#include "GameObjects/Background.h"
#include "GameObjects/Bird.h"
#include "GameObjects/Pipe.h"
#include "GameObjects/Score.h"

#include "GUI/Widget.h"
#include "GUI/IconButton.h"
#include "GUI/Label.h"

#include "Audio/Audio.h"
#include "Audio/Sound.h"
#include "Audio/Music.h"

class Game;

class ResourceHolder
{
private:
	Game* game;

public:
	std::unique_ptr<Background> background;
	std::unique_ptr<Score> score;
	std::shared_ptr<Bird> bird;
	std::array<std::shared_ptr<Pipe>, PIPE_NUM> pipes;

	std::map<std::string, std::unique_ptr<IconButton>> buttons;
	std::map<std::string, std::unique_ptr<Label>> labels;
	std::map<std::string, std::shared_ptr<Audio>> audio;

private:
	void addGameObjects();
	void addWidgets();
	void addAudio();

public:
	ResourceHolder(Game* game);

	ResourceHolder(const ResourceHolder&) = delete;
	ResourceHolder& operator=(const ResourceHolder&) = delete;
};

