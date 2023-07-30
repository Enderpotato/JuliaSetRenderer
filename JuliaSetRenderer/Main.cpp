#include "ComplexH.hpp"
#include "SFMLFuncsH.hpp"

int windowWidth = 720;
int windowHeight = 720;

using String = std::string;

int main()
{
	int testX = 720;
	int testY = 360;

	Complex c(-.79f, .15f);

	//std::cout << a.getMag() << std::endl;

	std::vector<int> JuliaSet = getJuliaSet(testX, testY, c);

	float lenX = static_cast<float>(windowWidth) / testX;
	float lenY = static_cast<float>(windowHeight) / testY;

	std::cout << lenX << " " << lenY << "\n";

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "window");

	while (window.isOpen())
	{
		window.clear();


		std::map<String, float> params;
		params["testX"] = (float)testX;
		params["testY"] = (float)testY;
		params["lenX"] = lenX;
		params["lenY"] = lenY;

		RenderJuliaSet(params, JuliaSet, window);
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