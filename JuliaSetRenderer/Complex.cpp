#include <iostream>
#include "Complex.hpp"


Complex::~Complex()
{
	//std::cout << "Complex destructed!" << std::endl;
}


Complex Complex::operator+(const Complex &other) const
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
	std::cout << this->re << "+ i" << this->im << std::endl;
}
