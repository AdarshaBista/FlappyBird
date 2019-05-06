#pragma once

#include <SFML/Audio.hpp>
#include "Audio.h"

class Sound : public Audio
{
private:
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;

public:
	Sound(const std::string& path);

	virtual void play() override;
	virtual void pause() override;
	virtual void stop() override;
};

