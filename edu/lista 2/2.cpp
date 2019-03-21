// iteracyjna - {int x=a[--n]; while(n--)if(t[n]<x)x=t[n];return x;}
// rekurencyjna - znajdŸ maksimum (n-1)-elementów; porównaj je z ostatnim elementem
// rekurencyjna - podziel tablicê na dwie czêœci; znajdŸ ich maksima; wybierz wiêkszez nich
#include <iostream>

int maks1 (int t[], int n) {
    int x = t[--n];
    while(n--)
        if(t[n] > x)
            x = t[n];

    return x;
}

int maks2 (int t[], int n) {
    if(n == 1)
        return t[0];

    if(t[n - 1] > maks2(t, n-1))
        return t[n-1];

    return maks2(t, n-1);
}

int maks3 (int t[], int l, int r) {
    if(r - 1 == 1)
        return t[1];
    int m = (1 + r) / 2;
    int u = maks3(t, l, m);
    int v = maks3(t, m, r);

    return u > v ? u : v;
}
