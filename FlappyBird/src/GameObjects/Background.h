#pragma once

#include <array>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Values/Values.h"
#include "Engine/GameObject.h"

class Background : public GameObject
{
private:
	std::array <std::vector<std::string>, BACKGROUNDS_NUM> backgrounds;
	std::array <std::vector<sf::Texture>, BACKGROUNDS_NUM> layersTex;
	std::vector <std::pair<sf::Sprite, sf::Sprite>> layers;

	float speed;
	int currentBackground;

public:
	Background();
	void loadLayers();
	void loadNextBackground();
	void loadPreviousBackground();

	virtual void handleEvents(const sf::Event& event) override;
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void reset() override;

};

