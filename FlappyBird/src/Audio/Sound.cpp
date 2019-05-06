#include "Sound.h"


Sound::Sound(const std::string& path)
{
	soundBuffer.loadFromFile(path);
	sound.setBuffer(soundBuffer);
	sound.setVolume(60.0f);
}

void Sound::play()
{
	sound.play();
}

void Sound::pause()
{
	sound.pause();
}

void Sound::stop()
{
	sound.stop();
}
