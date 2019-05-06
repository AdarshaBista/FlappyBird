#include "BackGround.h"


Background::Background() : speed(0.5f), currentBackground(1)
{
	// Load all backgrounds
	backgrounds[0] = DESERT_LAYER_PATHS;
	backgrounds[1] = FOREST_LAYER_PATHS;
	backgrounds[2] = LAKE_LAYER_PATHS;
	backgrounds[3] = WATERFALL_LAYER_PATHS;

	// Load textures of layers in each background
	for (unsigned int i = 0; i < BACKGROUNDS_NUM; ++i)
	{
		for (unsigned int j = 0; j < backgrounds[i].size(); ++j)
		{
			sf::Texture layerTex;
			layerTex.setSmooth(true);
			layerTex.loadFromFile(backgrounds[i][j]);
			layersTex[i].emplace_back(layerTex);
		}
	}

	loadLayers();
}

void Background::loadLayers()
{
	layers.clear();
	for (unsigned int i = 0; i < backgrounds[currentBackground].size(); ++i)
	{
		// Create sprite from texture
		sf::Sprite layer;
		layer.setTexture(layersTex[currentBackground][i]);

		// Add sprites to layer
		layers.emplace_back(std::make_pair(layer, layer));

		// Flip the second sprite along x-axis in each layer
		layers[i].second.setScale(-1.0f, 1.0f);

		// Set position of first sprite in each layer
		layers[i].first.setPosition(0.0f, 0.0f);

		// Set position of second sprite in each layer
		layers[i].second.setPosition(2 * layers[i].first.getLocalBounds().width, 0.0f);
	}
}

void Background::loadNextBackground()
{
	currentBackground++;
	if (currentBackground == BACKGROUNDS_NUM)
		currentBackground = 0;
	loadLayers();
}

void Background::loadPreviousBackground()
{
	currentBackground--;
	if (currentBackground < 0)
		currentBackground = BACKGROUNDS_NUM - 1;
	loadLayers();
}

void Background::handleEvents(const sf::Event& event)
{
}

void Background::update()
{
	speed += 0.00005f;

	// Move layers with different speeds
	for (unsigned int i = 0; i < layers.size(); ++i)
	{
		layers[i].first.move(-speed / 1.5f * (float)(i + 1), 0.0f);
		layers[i].second.move(-speed / 1.5f * (float)(i + 1), 0.0f);

		// Wrap layers in background
		// Check for first sprite
		if (layers[i].first.getPosition().x + layers[i].first.getLocalBounds().width < 0.0f)
			layers[i].first.setPosition(layers[i].second.getPosition().x, 0.0f);

		// Check for second sprite
		if (layers[i].second.getPosition().x < 0.0f)
			layers[i].second.setPosition(layers[i].first.getPosition().x + 2 * layers[i].first.getLocalBounds().width, 0.0f);
	}
}

void Background::draw(sf::RenderWindow & window)
{
	for (auto& layer : layers)
	{
		window.draw(layer.first);
		window.draw(layer.second);
	}
}

void Background::reset()
{
	speed = 0.5f;
}
