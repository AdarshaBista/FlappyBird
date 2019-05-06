#pragma once

#include <SFML/Audio.hpp>
#include "Audio.h"

class Music : public Audio
{
private:
	sf::Music music;

public:
	Music(const std::string& path);

	virtual void play() override;
	virtual void pause() override;
	virtual void stop() override;
};

