#include <iostream>
#include <math.h>

double f(double x) {
    return sin(x);
}

double bisection(double a, double b) {
    double c = a;

    if (f(a) * f(b) >= 0) {
        std::cout << "Error" << std::endl;
    }

    do {
        c = (b + a)/2;
        if (f(c) == 0)
            return c;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    } while (b - a >= 0.1);
    return c;
}




int main() {
    std::cout << bisection(-0.2, 0.8) << std::endl;
}
