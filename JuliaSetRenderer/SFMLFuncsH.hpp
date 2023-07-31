#pragma once

#include <SFML/Graphics.hpp>

sf::Color HSVColor(const float& h, const float& s, const float& l);

void RenderJuliaSet(
	std::map<std::string, float> params,
	const std::vector<int>& JuliaSet,
	sf::RenderWindow& window,
	int maxCount
);

void testRender(int width, int height, sf::RenderWindow& window);

float map(float x, float in_min, float in_max, float out_min, float out_max);
