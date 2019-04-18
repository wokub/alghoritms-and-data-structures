#include <iostream>

int max(int t[], int n) {
    int m = t[0];
    for (int i = 1; i < n; i++)
        if (t[i] > m)
            m = t[i];
    return m;
}

void countingSort(int t[], int n, int c) {
    int tmp[n];
    int x[10] = {0};

    for (int i = 0; i < n; i++)
        x[(t[i] / c) % 10]++;

    for (int i = 1; i < 10; i++)
        x[i] += x[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        tmp[x[(t[i] / c) % 10] - 1] = t[i];
        x[(t[i] / c) % 10]--;
    }

    for (int i = 0; i < n; i++)
        t[i] = tmp[i];
}









void radixSort(int t[], int n) {
    int m = max(t, n);

    for (int c = 1; m/c > 0; c *= 10)
        countingSort(t, n, c);
}



int main() {
    int t[] = {1,34,123,321,432,132,
                543,651,91,32,987,910,
                643,641,12,342,498,987,
                965,122,121,431,350};
    int n = sizeof(t)/sizeof(t[0]);
    
    radixSort(t, n);
    
    return 0;
}



