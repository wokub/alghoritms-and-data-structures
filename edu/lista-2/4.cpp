#include <iostream>

void f(int tab[], int k, int n) {
    int temp, _temp;

    for(int i = 0; i < k; i++) {
        temp = tab[n - 1];
        for(int j = 0; j < n; j++) {
            _temp = tab[j];
            tab[j] = temp;
            temp = _temp;
        }
    }
}

int main() {
    int n = 20;
    int tab[n];

    for(int i = 0; i < n; i++) {
        tab[i] = i;
        std::cout << tab[i] << " ";
    }

    f(tab, 5, n);
    std::cout << std::endl;

    for(int i = 0; i < n; i++) {
        std::cout << tab[i] << " ";
    }
}
