#include "Game.h"


Game::Game() : currentState(MENU)
{
	res = std::make_unique<ResourceHolder>(this);
}

void Game::run()
{
	res->audio["theme"]->play();

	while (app.getWindow().isOpen())
	{
		sf::Event event;
		while (app.getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				app.getWindow().close();
			
			handleEvents(event);
		}

		update();
		app.getWindow().clear();
		draw(app.getWindow());
		app.getWindow().display();
	}
}

void Game::handleEvents(const sf::Event& event)
{
	switch (currentState)
	{
	case MENU:
		for (auto& button : res->buttons)
			button.second->handleEvents(app.getWindow(), event);

		break;

	case RUNNING:
		res->bird->handleEvents(event);
		break;

	case GAMEOVER:
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right)
		{
			currentState = MENU;
			res->background->reset();
			res->bird->reset();
			res->score->reset();
			for (auto& pipe : res->pipes)
				pipe->reset();
		}
		break;

	default: break;
	}
}

void Game::update()
{
	switch(currentState)
	{
	case MENU:
		res->background->update();
		for (auto& button : res->buttons)
			button.second->update(app.getWindow());

		break;

	case RUNNING:
		res->background->update();
		res->score->update();
		res->bird->update();

		for (auto& pipe : res->pipes)
			pipe->update();

		for (auto& pipe : res->pipes)
			res->bird->checkCollision(*pipe);

		break;
	
	case GAMEOVER:
		res->background->update();
		res->bird->update();
		for (auto& pipe : res->pipes)
			pipe->update();
		break;

	default: break;
	}
}

void Game::draw(sf::RenderWindow& window)
{
	switch (currentState)
	{
	case MENU:
		res->background->draw(window);
		res->labels["title"]->draw(window);
		for (auto& button : res->buttons)
			button.second->draw(window);

		break;

	case RUNNING:
		res->background->draw(window);
		res->bird->draw(window);
		for (auto& pipe : res->pipes)
			pipe->draw(window);
		res->score->draw(window);

		break;

	case GAMEOVER:
		res->background->draw(window);
		res->labels["gameover"]->draw(window);
		res->labels["continue"]->draw(window);

		for (auto& pipe : res->pipes)
			pipe->draw(window);

		res->score->draw(window);
		res->bird->draw(window);

		break;

	default: break;
	}
}
