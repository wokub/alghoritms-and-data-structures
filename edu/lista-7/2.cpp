#include <bits/stdc++.h>

int f(int n) {
    int temp = 0;
    
    while(n) {
        temp += n & 1;
        n >>= 1;
    }
    
    return temp;
}

int main() {
    std::cout << countSetBits(10);

    return 0;
}