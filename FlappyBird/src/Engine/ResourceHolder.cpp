#include "ResourceHolder.h"

ResourceHolder::ResourceHolder(Game* game) : game(game)
{
	addAudio();
	addGameObjects();
	addWidgets();
}

void ResourceHolder::addAudio()
{
	audio["theme"] = std::make_shared<Music>(THEME_SOUND_PATH);
	audio["click"] = std::make_shared<Sound>(CLICK_SOUND_PATH);
	audio["score"] = std::make_shared<Sound>(SCORE_SOUND_PATH);
	audio["flap"] = std::make_shared<Sound>(FLAP_SOUND_PATH);
	audio["hit"] = std::make_shared<Sound>(HIT_SOUND_PATH);
}

void ResourceHolder::addGameObjects()
{
	background = std::make_unique<Background>();

	bird = std::make_shared<Bird>(audio["flap"]);
	bird->setOnCollisionCallBack([&]() { 
		audio["hit"]->play();
		game->currentState = game->GAMEOVER; 
	});

	for (int i = 0; i < PIPE_NUM; ++i)
		pipes[i] = std::make_shared<Pipe>(i);

	score = std::make_unique<Score>(bird, pipes, audio["score"]);
}

void ResourceHolder::addWidgets()
{
	buttons["play"] = std::make_unique<IconButton>(PLAY_BUTTON_PATH, sf::Vector2f(0.4f * WIDTH, HEIGHT / 1.3f), audio["click"]);
	buttons["exit"] = std::make_unique<IconButton>(EXIT_BUTTON_PATH, sf::Vector2f(0.6f * WIDTH, HEIGHT / 1.3f), audio["click"]);
	buttons["rightArrow"] = std::make_unique<IconButton>(RIGHT_ARROW_BUTTON_PATH, sf::Vector2f(0.05f * WIDTH, HEIGHT / 2.0f), audio["click"]);
	buttons["leftArrow"] = std::make_unique<IconButton>(LEFT_ARROW_BUTTON_PATH, sf::Vector2f(0.95f * WIDTH, HEIGHT / 2.0f), audio["click"]);

	buttons["play"]->setCallback([&]() { game->currentState = game->RUNNING; });
	buttons["exit"]->setCallback([&]() { game->app.getWindow().close(); });
	buttons["rightArrow"]->setCallback([&]() { background->loadNextBackground(); });
	buttons["leftArrow"]->setCallback([&]() { background->loadPreviousBackground(); });
	
	labels["title"] = std::make_unique<Label>("FLAPPY BIRD", sf::Vector2f(WIDTH / 2.0f, HEIGHT / 6.0f), 110);
	labels["gameover"] = std::make_unique<Label>("You Died", sf::Vector2f(WIDTH / 2.0f, HEIGHT / 3.0f), 100);
	labels["continue"] = std::make_unique<Label>("Right click to continue", sf::Vector2f(WIDTH / 2.0f, HEIGHT / 2.0f), 50);
}