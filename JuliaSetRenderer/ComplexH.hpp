#include <iostream>
#include <vector>

struct Complex
{
	float re, im;
public:
	Complex(float re, float im):
		re(re), im(im) {
		//std::cout << "Complex constucted!" << std::endl;
	}

	~Complex();

	Complex operator+(const Complex& other) const;

	Complex operator*(const Complex& other) const;

	void print() const;

	float getMag() const;
};

std::vector<int> getJuliaSet(const int& width, const int& height, const Complex& c);

int outOfRange(Complex z, const Complex& c, const int& maxCount);