class Complex
{
private:
	float re, im;
	float r, theta;
public:
	Complex(float re, float im):
		re(re), im(im) {}

	Complex operator+(Complex other);
};