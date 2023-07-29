#include <iostream>

struct Complex
{
	float re, im;
	float r, theta;
public:
	Complex(float re, float im):
		re(re), im(im) {
		//std::cout << "Complex constucted!" << std::endl;
	}

	~Complex();

	Complex operator+(const Complex &other) const;

	Complex operator*(const Complex &other) const;

	void print() const;
};
