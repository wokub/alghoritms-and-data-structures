#include <iostream>

int f(int n) {
    int temp = 0;

    while(n > 0) {
        temp += n % 2;
        n /= 2;
    }

    return temp;
}

int main() {
    std::cout << f(10);

    return 0;
}
