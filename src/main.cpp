#include <SFML/Graphics.hpp>
#include "constants.h"
#include "ArcadeRacer.h"




int main()
{
	sf::RenderWindow window(sf::VideoMode(sScreenWidth, sScreenHeight), "3d Arcade Racer");			// defines OS window able to receive OpenGL rendering
	PixelGrid pixelGrid;						// handles pixel rendering 
	ArcadeRacer game(pixelGrid);				// performs game logic 
	sf::Clock clock;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time frameTime = clock.getElapsedTime();
		clock.restart();

		window.clear();
		game.update(frameTime.asSeconds());
		pixelGrid.update();


		const sf::Texture& texture = pixelGrid.getTexture();
		sf::Sprite sprite(texture);

		window.draw(sprite);
		window.display();
	}




	return 0;
}
