#include "PixelGrid.h"
#include "constants.h"
#include <math.h>

PixelGrid::PixelGrid()
{	
	
	// creates a render texture of same dimensions as render window
	mRenderTex.create(sScreenWidth, sScreenHeight);
	
	// creates a raster pixel grid tilemap
	mVertices.setPrimitiveType(sf::Quads);
	mVertices.resize(sRasterPixelWidth*sRasterPixelHeight * 4);

	const double pixWidth = sScreenWidth / (double)sRasterPixelWidth;
	const double pixHeight = sScreenHeight / (double)sRasterPixelHeight;


	for (unsigned y = 0; y < sRasterPixelHeight; y++)
	{
		for (unsigned x = 0; x < sRasterPixelWidth; x++)
		{
			sf::Vertex* quad = &mVertices[(x + y * sRasterPixelWidth) * 4];

			// updates the location for each pixel vertice
			// starts from bottom left vertice and goes clockwise
			quad[0].position = sf::Vector2f(x*pixWidth, y*pixHeight);
			quad[1].position = sf::Vector2f((x + 1) * pixWidth, y * pixHeight);
			quad[2].position = sf::Vector2f((x + 1) * pixWidth, (y + 1) * pixHeight);
			quad[3].position = sf::Vector2f(x * pixWidth, (y + 1) * pixHeight);


			quad[0].color = sf::Color::Black;
			quad[1].color = sf::Color::Black;
			quad[2].color = sf::Color::Black;
			quad[3].color = sf::Color::Black;

		}
	}
}

void PixelGrid::update()
{
	mRenderTex.draw(mVertices);
}


void PixelGrid::setPixel(sf::Vector2u pos, sf::Color col)
{
	pos.y = abs((int)pos.y - 99);

	sf::Vertex* quad = &mVertices[(pos.x + pos.y * sRasterPixelWidth) * 4];

	quad[0].color = col;
	quad[1].color = col;
	quad[2].color = col;
	quad[3].color = col;
}


sf::Color PixelGrid::getPixel(sf::Vector2u pos)
{

	sf::Vertex* quad = &mVertices[(pos.x + pos.y * sRasterPixelWidth) * 4];
	return quad[0].color;
}



const sf::Texture& PixelGrid::getTexture()
{
	return mRenderTex.getTexture();
}