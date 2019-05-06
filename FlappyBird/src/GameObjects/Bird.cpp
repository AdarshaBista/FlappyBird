#include "Bird.h"


Bird::Bird(std::shared_ptr<Audio> flapSound) : flapSound(flapSound), maxGravity(13.0f), gravityAcc(1.8f),
												maxAngle(40.0f), angleAcc(2.5f), 
												dir(DOWN), gravity(4.0f), angle(0.0f)
{
	// Load bird textures
	for (int i = 0; i < BIRD_NUM; ++i)
	{
		birdTex[i].loadFromFile(BIRD_PATHS[i]);
		birdTex[i].setSmooth(true);
	}
	frameIndex = 0;
	bird.setTexture(birdTex[frameIndex]);

	// Load light texture
	lightTex.loadFromFile(BIRD_LIGHT_PATH);
	lightTex.setSmooth(true);
	light.setTexture(lightTex);
	light.setColor(sf::Color(0, 200, 200, 180));

	bird.setOrigin(bird.getGlobalBounds().width / 2.0f, bird.getGlobalBounds().height / 2.0f);
	bird.setPosition(WIDTH / 3.0f, HEIGHT / 8.0f);
	bird.setRotation(0.0f);
	bird.setScale(0.35f, 0.35f);

	light.setOrigin(light.getGlobalBounds().width / 2.0f, light.getGlobalBounds().height / 2.0f);
	light.setPosition(bird.getPosition());

	animateElapsed = animateClock.restart();
}

void Bird::setOnCollisionCallBack(std::function<void()> onCollisionCallback)
{
	onCollision = onCollisionCallback;
}

void Bird::moveUp()
{
	// Only if bird is falling
	if (dir == DOWN)
	{
		dir = UP;
		flightElapsed = flightClock.restart();
	}
}

// Check collision with pipes and ground
void Bird::checkCollision(Pipe& pipe)
{
	if (pipe.getPipes().first.getGlobalBounds().contains(bird.getPosition()) ||
		pipe.getPipes().second.getGlobalBounds().contains(bird.getPosition()) ||
		bird.getPosition().y > HEIGHT ||
		bird.getPosition().y < 0.0f)
		onCollision();
}

sf::Vector2f Bird::getPosition()
{
	return bird.getPosition();
}

// Animate Bird
void Bird::animate()
{
	animateElapsed = animateClock.getElapsedTime();

	int frameTime = 30;
	if (animateElapsed.asMilliseconds() > frameTime)
	{
		frameIndex++;
		if (frameIndex == BIRD_NUM)
			frameIndex = 0;
		bird.setTexture(birdTex[frameIndex]);
		animateElapsed = animateClock.restart();
	}
}

void Bird::handleEvents(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
	{
		if (event.key.code == sf::Keyboard::Up || event.mouseButton.button == sf::Mouse::Left)
		{
			moveUp();
			flapSound->play();
		}
	}
}

void Bird::update()
{
	// Gravity
	gravity += gravityAcc * dir;
	if (gravity > maxGravity || gravity < -maxGravity)
		gravity = maxGravity * dir;

	// Rotation
	angle += angleAcc * dir;
	if (angle > maxAngle || angle < -maxAngle)
		angle = maxAngle * dir;

	// Move bird down after 350 ms
	flightElapsed = flightClock.getElapsedTime();
	int flightTime = 350;
	if (flightElapsed.asMilliseconds() > flightTime)
		dir = DOWN;

	// Move and rotate bird
	bird.move(0.0f, gravity);
	light.move(0.0f, gravity);
	bird.setRotation(angle);

	// Animate bird
	animate();
}

void Bird::draw(sf::RenderWindow & window)
{
	window.draw(light);
	window.draw(bird);
}

void Bird::reset()
{
	dir = DOWN;
	gravity = 4.0f;
	angle = 0.0f;

	bird.setPosition(WIDTH / 3.0f, HEIGHT / 8.0f);
	light.setPosition(bird.getPosition());
}
