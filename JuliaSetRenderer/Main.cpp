#include <iostream>
#include <SFML/Graphics.hpp>
#include "Complex.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(720, 320), "window");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}
	}


	std::cout << "Hello world!" << std::endl;

	return 0;
}