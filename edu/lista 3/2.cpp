#include <climits>
#include <iostream>

void insertionSort(int a[], int n) {
    int v;
    a[-1] = INT_MIN;

    for (int i = 1; i <= n; i++) {
        v = a[i];
        int j = i;
        
        while (a[j-1] > v) {
            a[j] = a[j-1];
            j--;
        }
        
        a[j] = v;
    }
}

int main() {
    int tab[] = {3, -1, 2, 5, 8, 0, -4, 10};
    int k = sizeof(tab)/sizeof(tab[0]);

    insertionSort(tab, k);

    for(auto x : tab) {
        std::cout << x << " ";
    }
}
