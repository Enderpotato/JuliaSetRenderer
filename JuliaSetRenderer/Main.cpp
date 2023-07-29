#include <iostream>
#include <SFML/Graphics.hpp>
#include "ComplexH.hpp"

int windowWidth = 720;
int windowHeight = 360;


int main()
{
	int testX = 10;
	int testY = 5;

	Complex c(0, -1.f);

	getJuliaSet(testX, testY, c);


	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "window");

	sf::CircleShape circle;
	circle.getFillColor();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}
	}

	return 0;
}