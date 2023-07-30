#include <SFML/Graphics.hpp>
#include "SFMLFuncsH.hpp"

void RenderJuliaSet(
	std::map<std::string, float> params,
	const std::vector<int>& JuliaSet,
	sf::RenderWindow& window
)
{

	float testY = params["testY"];
	float testX = params["testX"];
	float lenX = params["lenX"];
	float lenY = params["lenY"];
	for (int i = 0; i < testY; i++)
	{
		for (int j = 0; j < testX; j++)
		{
			int iters = JuliaSet[static_cast<int>(i * testY + j)];

			//std::cout << iters << std::endl;
			sf::RectangleShape pixel;
			pixel.setPosition(j * lenX, i * lenY);
			pixel.setSize(sf::Vector2f(lenX, lenY));
			sf::Color pixelColor = (iters == 0) ? sf::Color::Red : sf::Color::Green;
			pixel.setFillColor(pixelColor);
			window.draw(pixel);
		}
	}
}

void testRender(int width, int height, sf::RenderWindow& window)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			float r = static_cast<float>(width - i) / width * 255;
			float g = static_cast<float>(j) / height * 255;
			float b = static_cast<float>(i) / width * 255;
			sf::Color pixelC = sf::Color(r, g, b);
			sf::RectangleShape pixel;
			pixel.setSize(sf::Vector2f(1.f, 1.f));
			pixel.setPosition(i, j);
			pixel.setFillColor(pixelC);
			window.draw(pixel);
		}
	}
}

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}