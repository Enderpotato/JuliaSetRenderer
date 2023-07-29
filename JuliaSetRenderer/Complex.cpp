#include <iostream>
#include <vector>
#include <math.h>
#include "ComplexH.hpp"


using String = std::string;

Complex::~Complex()
{
	//std::cout << "Complex destructed!" << std::endl;
}


Complex Complex::operator+(const Complex& other) const
{
	return Complex(this->re + other.re, this->im + other.im);
}

Complex Complex::operator*(const Complex& other) const
{
	float real = this->re * other.re - this->im * other.im;
	float imag = this->re * other.im + this->im * other.re;
	return Complex(real, imag);
}

void Complex::print() const
{
	std::cout << this->re;
	String iPrefix = (this->im < 0) ? "- i" : "+ i";
	std::cout << iPrefix << std::abs(this->im) << "\n";
}

std::vector<int> getJuliaSet(const int& width, const int& height, const Complex& c)
{
	std::vector<int> JuliaSet;


	int minLen = std::min(width, height);

	float gapSize = 2.f / minLen;
	float startX = static_cast<float>(-gapSize) * width / 2;
	float startY = static_cast<float>(-gapSize) * height / 2;

	std::cout << startX << std::endl;
	std::cout << startY << std::endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int count = 1;
			Complex z = Complex(
				startX + j * gapSize,
				startY + i * gapSize
			);
			z.print();

		}
	}

	std::cout << minLen << "\n";
	std::cout << gapSize << "\n";

	return JuliaSet;
}