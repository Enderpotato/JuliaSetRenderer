#include <SFML/Graphics.hpp>
#include "SFMLFuncsH.hpp"
#include <iostream>
#include <math.h>

// 0 <= h <= 360
// 0 <= s <= 1
// 0 <= l <= 1

sf::Color HSVColor(const float& h, const float& s, const float& l)
{
	float C = (1 - std::abs(2 * l - 1)) * s;
	float Hprime = h / 60;
	float X = C * (1 - std::abs(std::fmod(Hprime, 2) - 1));
	float m = l - C / 2;

	C = (C + m) * 255;
	X = (X + m) * 255;

	//std::cout << C << std::endl;
	//std::cout << Hprime << std::endl;
	//std::cout << X << std::endl;


	if (Hprime <= 1) return sf::Color(C + m, X + m, 0);
	if (Hprime <= 2) return sf::Color(X + m, C + m, 0);
	if (Hprime <= 3) return sf::Color(0, C + m, X + m);
	if (Hprime <= 4) return sf::Color(0, X + m, C + m);
	if (Hprime <= 5) return sf::Color(X + m, 0, C + m);
	return sf::Color(C + m, 0, X + m);

}



void RenderJuliaSet(
	std::map<std::string, float> params,
	const std::vector<int>& JuliaSet,
	sf::RenderWindow& window,
	int maxCount
)
{

	float renderX = params["renderX"];
	float renderY = params["renderY"];
	float lenX = params["lenX"];
	float lenY = params["lenY"];
	for (int i = 0; i < renderY; i++)
	{
		for (int j = 0; j < renderX; j++)
		{
			float hue = j / renderX * 360;
			int iterations = JuliaSet[i * renderY + j];
			sf::RectangleShape pixel;
			pixel.setPosition(j * lenX, i * lenY);
			pixel.setSize(sf::Vector2f(lenX, lenY));
			sf::Color pixelColor;
			if (iterations == 0) {
				pixelColor = HSVColor(hue, 1.f, 0.5f);
				//pixelColor = sf::Color::Blue;
			}
			else
			{
				float ratio = (float)iterations / (float)maxCount;
				//float r = ratio * 255;
				//float g = ratio * 165;
				//float b = 255 - ratio * 255;

				pixelColor = HSVColor(hue, 1.f, ratio);
				//pixelColor = sf::Color::Black;
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