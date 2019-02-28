#include <iostream>

double oblicz(double a[], int n, double x) {
    double tab = a[n];
    int res = 0;

    while (n) {
        tab *= x + a[--n];
        res++;
    }

    return res;
}

int main() {
    double a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};

    std::cout << "Liczba mnozen " << oblicz(a, sizeof(a)/sizeof(a[0]), 3) << std::endl;
}
