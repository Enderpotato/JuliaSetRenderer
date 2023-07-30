#include <SFML/Graphics.hpp>

sf::Color Color(float& r, float& g, float& b);

sf::Color Color(float& r, float& g, float& b, float& a);

void RenderJuliaSet(
	std::map<std::string, int> params,
	const std::vector<int>& JuliaSet,
	sf::Window& window
);