#include <iostream>
#include <SFML/Graphics.hpp>
#include "Complex.hpp"

int main()
{
	Complex* a = new Complex(1.f, 1.f);
	Complex* b = new Complex(2.f, 2.f);


	delete a;
	delete b;

	sf::RenderWindow window(sf::VideoMode(720, 320), "window");

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