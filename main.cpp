#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define PI 3.14159

int main ()
{
	float radius = 300;
	float radiusInc = 50;
	float angle = 0.0f;
	float angleInc = 15.0f;

	sf::RenderWindow window (sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Rainbow Swirl");
	sf::Clock clock;
	std::vector<sf::CircleShape> buffer;

	sf::Time lastFrame = clock.getElapsedTime();
	bool completed = false;

	while (window.isOpen())
	{
		sf::Time currentFrame = clock.getElapsedTime();
		sf::Time delta = currentFrame - lastFrame;
		lastFrame = currentFrame;
		
		//process all events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		//clear window
		window.clear();
		
		//draw triangles
		/* draw all triangles in buffer */
		for (int i = 0; i < buffer.size(); i++ )
			window.draw(buffer.at(i));
		
		/* create a new triangle : resize and rotate */
		if (!completed)
		{
			radius -= radiusInc * delta.asSeconds();
			sf::CircleShape triangle (radius, 3);
			triangle.setOrigin( radius, radius );
			triangle.setPosition( WINDOW_WIDTH/2, WINDOW_HEIGHT/2 );
			
			float x = (sin(currentFrame.asSeconds()*2)*127.5)+127.5;
			float y = (-sin(currentFrame.asSeconds()*2)*127.5)+127.5;
			triangle.setFillColor( sf::Color(50, y, x) );

			triangle.rotate(angle);
			angle += angleInc * delta.asSeconds();
		
			window.draw(triangle);
			buffer.push_back(triangle);
			
			if (angle > 360)
				angle = 0;

			if (radius < 1)
				completed = true;
		}
		
		//swap buffers
		window.display();
	}

	return 0;
}
