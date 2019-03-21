#include <iostream>
#include <cmath>

double f(double x) { return 2 * x - 1; }

double root(double a, double b) {
	double _f;
	double _a = f(a); 
	double _b = f(b);
	double x = (a + b) / 2;
	
	while (fabs(a - b) > 0.000001) {
		x = (a + b) / 2;
		_f = f(x);
		
		if (fabs(_f) < 0.000001) {
			break;
		} else if (_a * _b < 0) {
			b = x;
		} else {
			a = x; 
			_a = _f;
		}
	}
	return x;
}


int main(void) {
	std::cout << "f(0) : " << f(0) << "\nf(1) : " << f(1) << std::endl;
	std::cout << "Msc zerowe: " << root(2, 20) << std::endl;

	return 0;
}