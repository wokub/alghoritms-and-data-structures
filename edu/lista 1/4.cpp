#include <iostream>
#include <math.h>

double chance(int k, int n, double p) {
    double result = 0;

    double q, pq;

    q = 1 - p;
    pq = p / q;
    int temp = pow(q, n);

    for (int i = 1; i <= k; i++) {
        result += temp;
        temp *= (pq) * (n-i)/(i+1);
    }

    return result;
}

int main() {
    std::cout << chance(5, 20, 2) << std::endl;
}

