#include "Music.h"


Music::Music(const std::string& path)
{
	music.openFromFile(path);
	music.setLoop(true);
	music.setVolume(100.0f);
}

void Music::play()
{
	music.play();
}

void Music::pause()
{
	music.pause();
}

void Music::stop()
{
	music.stop();
}
