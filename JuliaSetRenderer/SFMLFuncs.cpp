#include <SFML/Graphics.hpp>
#include "SFMLFuncsH.hpp"
#include <map>


sf::Color newColor(float& r, float& g, float& b)
{
	return sf::Color(r * 255, g * 255, b * 255);
}

sf::Color newColor(float& r, float& g, float& b, float& a)
{
	return sf::Color(r * 255, g * 255, b * 255, a * 255);
}


void RenderJuliaSet(
	std::map<std::string, int> params,
	const std::vector<int>& JuliaSet,
	sf::Window& window
)
{

	int testY = params["testY"];
	int testX = params["testX"];
	int lenX = params["lenX"];
	int lenY = params["lenY"];
	for (int i = 0; i < testY; i++)
	{
		for (int j = 0; j < testX; j++)
		{
			int iters = JuliaSet[i * testY + j];

			//std::cout << iters << std::endl;
			sf::RectangleShape pixel;
			pixel.setPosition(j * lenX, i * lenY);
			pixel.setSize(sf::Vector2f(lenX, lenY));
			sf::Color pixelColor = (iters == 0) ? sf::Color::Red : sf::Color::Green;
			pixel.setFillColor(pixelColor);
		}
	}
}