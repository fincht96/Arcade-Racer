#include "ArcadeRacer.h"
#include "constants.h"
#include <iostream>
#include <math.h>

ArcadeRacer::ArcadeRacer(PixelGrid& const pixelGrid)
	: mPixelGrid(pixelGrid)
{



}




void ArcadeRacer::update(float fElapsedTime)
{




	// distance increases proportional to time
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		fDistance += 10.0f * fElapsedTime;






	// draw track
	for (unsigned y = 0; y < sRasterPixelHeight / 2; y++)		// track occupies bottom half of screen
	{
		for (unsigned x = 0; x < sRasterPixelWidth; x++)
		{
			float fPerspective = (float)y / (sRasterPixelHeight / 2.0f);

			float fMiddlePoint = 0.5f;
			float fRoadWidth = fPerspective*0.8f + 0.1f;
			float fClipWidth = fRoadWidth * 0.15f;

			fRoadWidth *= 0.5f;

			float nLeftClip = (fMiddlePoint - fRoadWidth) * sRasterPixelWidth;
			float nLeftGrass = (fMiddlePoint - fRoadWidth - fClipWidth) * sRasterPixelWidth;
			float nRightClip = (fMiddlePoint + fRoadWidth) * sRasterPixelWidth;
			float nRightGrass = (fMiddlePoint + fRoadWidth + fClipWidth) * sRasterPixelWidth;


			int nRow = sRasterPixelHeight / 2 + y;



			sf::Color grassColor = sinf(20.0f*pow(1.0f - fPerspective, 3) + fDistance * 2.0f) > 0.0f ? sf::Color(34, 139, 34) : sf::Color::Green;
			sf::Color clipColor = sinf(20.0f*pow(1.0f - fPerspective, 3) + fDistance * 5.0f) > 0.0f ? sf::Color::Red : sf::Color::White;






			if (x >= 0 && x < nLeftGrass)
				mPixelGrid.setPixel(sf::Vector2u(x,nRow), grassColor);

			if (x >= nLeftGrass && x < nLeftClip)
				mPixelGrid.setPixel(sf::Vector2u(x, nRow), clipColor);

			if (x >= nLeftClip && x < nRightClip)
				mPixelGrid.setPixel(sf::Vector2u(x, nRow), sf::Color(211,211,211));

			if (x >= nRightClip && x < nRightGrass)
				mPixelGrid.setPixel(sf::Vector2u(x, nRow), clipColor);

			if (x >= nRightGrass && x < sScreenWidth)
				mPixelGrid.setPixel(sf::Vector2u(x, nRow), grassColor);

		}
	}

	fCarPos = 0.0;

	// Draw car
	int nCarPos = sRasterPixelWidth / 2 + ((int)sRasterPixelWidth*fCarPos / 2.0f) - sCarWidth;		

	// line 1
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 4, 80), sf::Color(0,187,212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 5, 80), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 6, 80), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 7, 80), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 8, 80), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 9, 80), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 10, 80), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 11, 80), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 12, 80), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 13, 80), sf::Color(0, 187, 212));
	
	// line 2
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 4, 81), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 5, 81), sf::Color(96, 125, 139));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 6, 81), sf::Color(96, 125, 139));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 7, 81), sf::Color(96, 125, 139));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 8, 81), sf::Color(96, 125, 139));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 9, 81), sf::Color(96, 125, 139));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 10, 81), sf::Color(96, 125, 139));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 11, 81), sf::Color(96, 125, 139));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 12, 81), sf::Color(96, 125, 139));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 13, 81), sf::Color(0, 187, 212));

	// line 3
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 0, 82), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 1, 82), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 2, 82), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 4, 82), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 8, 82), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 9, 82), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 13, 82), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 15, 82), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 16, 82), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 17, 82), sf::Color::Black);

	// line 4
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 0, 83), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 1, 83), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 2, 83), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 4, 83), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 7, 83), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 8, 83), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 9, 83), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 10, 83), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 13, 83), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 15, 83), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 16, 83), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 17, 83), sf::Color::Black);

	// line 5
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 0, 84), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 1, 84), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 2, 84), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 3, 84), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 4, 84), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 5, 84), sf::Color(96, 125, 139));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 6, 84), sf::Color(96, 125, 139));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 7, 84), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 8, 84), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 9, 84), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 10, 84), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 11, 84), sf::Color(96, 125, 139));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 12, 84), sf::Color(96, 125, 139));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 13, 84), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 14, 84), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 15, 84), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 16, 84), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 17, 84), sf::Color::Black);


	// line 6
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 0, 85), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 1, 85), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 2, 85), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 4, 85), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 5, 85), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 6, 85), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 7, 85), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 8, 85), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 9, 85), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 10, 85), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 11, 85), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 12, 85), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 13, 85), sf::Color(0, 187, 212));
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 15, 85), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 16, 85), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 17, 85), sf::Color::Black);


	// line 7
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 0, 86), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 1, 86), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 2, 86), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 15, 86), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 16, 86), sf::Color::Black);
	mPixelGrid.setPixel(sf::Vector2u(nCarPos + 17, 86), sf::Color::Black);





	
}




