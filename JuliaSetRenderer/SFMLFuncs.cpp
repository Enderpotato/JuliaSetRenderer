#include <SFML/Graphics.hpp>
#include "SFMLFuncsH.hpp"

sf::Color Color(float& r, float& g, float& b)
{
	return sf::Color(r * 255, g * 255, b * 255);
}

sf::Color Color(float& r, float& g, float& b, float& a)
{
	return sf::Color(r * 255, g * 255, b * 255, a * 255);
}