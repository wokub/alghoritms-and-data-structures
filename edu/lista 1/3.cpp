#include <iostream>

double oblicz(double a[], int n,double x) {
    int res = a[0];

	for(int i = 1; i <= n; i++) {
		res = res * x + a[i];
    }
	
	return res;
}

int main() {
    double tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    
    std::cout << oblicz(tab, 5, 3) << std::endl;
    
    return 0;
}