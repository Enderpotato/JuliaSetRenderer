class Complex
{
private:
	float re, im;
public:
	Complex(float re, float im):
		re(re), im(im) {}

	Complex operator+(Complex other);
};