#ifndef ARCADERACER_H
#define ARCADERACER_H

#include <SFML/Graphics.hpp>
#include "PixelGrid.h"






class ArcadeRacer
{
public:
	ArcadeRacer(PixelGrid& const pixelGrid);
	void update(float fElapsedTime);

private:
	float fCarPos;
	PixelGrid& const mPixelGrid;
	float fDistance = 0.0f;
	float fElapsedTime;
};










#endif