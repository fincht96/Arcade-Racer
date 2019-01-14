#pragma once

#include <SFML/Graphics.hpp>



class PixelGrid
{
public:
	PixelGrid();
	void update();
	void setPixel(sf::Vector2u pos, sf::Color col);
	sf::Color getPixel(sf::Vector2u pos);

	const sf::Texture& getTexture();

private:
	sf::VertexArray mVertices;			// represents a raster pixel grid
	sf::RenderTexture mRenderTex;		// used for drawing off screen
};