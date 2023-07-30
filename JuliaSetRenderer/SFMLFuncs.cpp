#include <SFML/Graphics.hpp>
#include "SFMLFuncsH.hpp"
#include <iostream>

void RenderJuliaSet(
	std::map<std::string, float> params,
	const std::vector<int>& JuliaSet,
	sf::RenderWindow& window,
	int maxCount
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
			int iterations = JuliaSet[i * testY + j];
			sf::RectangleShape pixel;
			pixel.setPosition(j * lenX, i * lenY);
			pixel.setSize(sf::Vector2f(lenX, lenY));
			sf::Color pixelColor;
			if (iterations == 0) {
				//pixelColor = sf::Color(255, 165, 0);
				pixelColor = sf::Color::Blue;
			}
			else
			{
				float ratio = (float)iterations / (float)maxCount;
				//int r = static_cast<int>(iterations / (maxCount) * 255);
				//int g = static_cast<int>(iterations / (maxCount) * 165);
				int b = 255 - ratio * 255;
				//std::cout << iterations / maxCount << std::endl;

				pixelColor = sf::Color(0, 0, b, ratio * 255);
			}
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