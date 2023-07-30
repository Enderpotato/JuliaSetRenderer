#include "ComplexH.hpp"
#include "SFMLFuncsH.hpp"

int windowWidth = 1000;
int windowHeight = 1000;

using String = std::string;

int main()
{
	int renderX = 1500;
	int renderY = 1500;

	Complex c(.28f, 0.008f);

	//std::cout << a.getMag() << std::endl;
	int maxCount = 100;

	std::vector<int> JuliaSet = getJuliaSet(renderX, renderY, c, maxCount);

	float lenX = static_cast<float>(windowWidth) / renderX;
	float lenY = static_cast<float>(windowHeight) / renderY;

	std::cout << lenX << " " << lenY << "\n";

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "window");

	while (window.isOpen())
	{
		window.clear();


		std::map<String, float> params;
		params["renderX"] = (float)renderX;
		params["renderY"] = (float)renderY;
		params["lenX"] = lenX;
		params["lenY"] = lenY;

		RenderJuliaSet(params, JuliaSet, window, maxCount);
		//testRender(windowWidth, windowHeight, window);
		
		window.display();


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}
	}

	return 0;
}