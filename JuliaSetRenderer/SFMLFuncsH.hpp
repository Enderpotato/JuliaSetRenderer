#include <SFML/Graphics.hpp>

sf::Color newColor(float& r, float& g, float& b);

sf::Color newColor(float& r, float& g, float& b, float& a);

sf::Color Color(float& r, float& g, float& b, float& a);

void RenderJuliaSet(
	std::map<std::string, int> params,
	const std::vector<int>& JuliaSet,
	sf::Window& window
);