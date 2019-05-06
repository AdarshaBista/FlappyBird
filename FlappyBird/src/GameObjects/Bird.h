#pragma once

#include <array>
#include <memory>
#include <functional>
#include <SFML/Graphics.hpp>

#include "Values/Values.h"
#include "Audio/Audio.h"
#include "Engine/GameObject.h"
#include "Pipe.h"

class Bird : public GameObject
{
private:
	// Light behind bird
	sf::Texture lightTex;
	sf::Sprite light;

	// Bird
	std::array <sf::Texture, BIRD_NUM> birdTex;
	sf::Sprite bird;

	enum BirdDir : short int { UP = -1, DOWN = 1 } dir;

	const float maxGravity;
	const float gravityAcc;
	float gravity;

	const float maxAngle;
	const float angleAcc;
	float angle;

	// For bird animations
	int frameIndex;
	sf::Clock flightClock;
	sf::Time flightElapsed;
	sf::Clock animateClock;
	sf::Time animateElapsed;

	std::function<void()> onCollision;
	std::shared_ptr<Audio> flapSound;

private:
	void moveUp();
	void animate();

public:
	Bird(std::shared_ptr<Audio> flapSound);
	void setOnCollisionCallBack(std::function<void()> onCollisionCallback);
	void checkCollision(Pipe& pipe);
	sf::Vector2f getPosition();

	virtual void handleEvents(const sf::Event& event) override;
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void reset() override;

};