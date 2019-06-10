#include <iostream>

int f(int n) {
    int temp = 0;

    while(n > 0) {
        temp += n % 2;  // najmniej znaczący bit
        n /= 2;         // kolejny bit
    }

    return temp;
}

int main() {
    std::cout << f(10);

    return 0;
}


/*
Wykonania pętli while dla f(10)
1.  temp = 0 n = 5
2.  temp = 1 n = 2
3.  temp = 1 n = 1
4.  temp = 2 n = 0
    n > 0 = false
*/