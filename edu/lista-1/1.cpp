#include <iostream>

int reku(int x, int n) {
    if(n == 0) {
        return 1;
    } else if((n % 2) != 0) {
        return x * reku(x * x, n/2);
    } else
        return reku(x * x, n/2);
}

int iter(int x, int n) {
    int result = 1;
    
    while (n > 0) {
        if ((n % 2) != 0) {
            result *= x;
        }
        n /= 2;
        x *= x;
    }
    return result;
}

int main() {
    std::cout << iter(2, 5) << std::endl;
    std::cout << reku(2, 5) << std::endl;
}