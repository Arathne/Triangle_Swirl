#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define PI 3.14159

void processKeyboard (void);

std::vector<sf::CircleShape> buffer;

float radius = 300;
float radiusInc = 1;
float angle = 0.0f;
float angleInc = 1.0f;
int timer = 10;
bool completed = false;

int main ()
{
	sf::RenderWindow window (sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Rainbow Swirl");
	sf::Clock clock;
	
	sf::Font font;
	if (!font.loadFromFile(FONT))
	{
		return -1;
	}

	sf::Time lastDraw = clock.getElapsedTime();

	while (window.isOpen())
	{
		//process all events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
				processKeyboard();
		}
		
		//clear window
		window.clear();
		
		//draw triangles
		/* draw all triangles in buffer */
		for (int i = 0; i < buffer.size(); i++ )
			window.draw(buffer.at(i));
		
		sf::Time currentDraw = clock.getElapsedTime();
		sf::Time elapsedTime = currentDraw - lastDraw;
		
		/* create a new triangle : resize and rotate */
		if (!completed && elapsedTime.asMilliseconds() > timer)
		{
			radius -= radiusInc;
			
			sf::CircleShape triangle (radius, 3);
			triangle.setOrigin( radius, radius );
			triangle.setPosition( WINDOW_WIDTH/2, WINDOW_HEIGHT/2 );
			
			float x = (sin(currentDraw.asSeconds()*2)*127.5)+127.5;
			float y = (-sin(currentDraw.asSeconds()*2)*127.5)+127.5;
			triangle.setFillColor( sf::Color(50, y, x) );

			triangle.rotate(angle);
			angle += angleInc;
		
			window.draw(triangle);
			buffer.push_back(triangle);
			
			if (angle > 360)
				angle = 0;

			if (radius < 1)
				completed = true;
			
			lastDraw = currentDraw;
		}
		
		sf::Text timeText;
		timeText.setFont(font);
		timeText.setString("TIMER");
		timeText.setPosition(0,0);
		timeText.setCharacterSize(30);
		timeText.setFillColor(sf::Color::Red);
		window.draw(timeText);
		
		//swap buffers
		window.display();
	}
	
	return 0;
}

void processKeyboard (void)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		radius = 300;
		angle = 0.0f;
		completed = false;
		buffer.clear();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (timer <= 1000)
			timer += 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		if (timer > 0)
			timer -= 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		radiusInc += 0.05;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		radiusInc -= 0.05;
		
		if (radiusInc < 0)
			radiusInc = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		angleInc += 0.05;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		angleInc -= 0.05;
		
		if (angleInc < 0)
			angleInc = 0;
	}

	std::cout << "TIME: " << timer << std::endl;
	std::cout << "RADIUS INC: " << radiusInc << std::endl;
	std::cout << "ANGLE INC: " << angleInc << std::endl;
}
