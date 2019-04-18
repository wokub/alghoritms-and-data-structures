int partition (int n, double t[]) {
    int k = -1;
    double l = t[n / 2];
    
    while (true) {
        // za pomocą petli while rozdzielamy elementy tablicy na mniejsze i większe
        // względem elementu l
        while (t[--n] > l);
        while (t[++k] < l);
        if (n > k) {
            double y = t[k];
            t[k] = t[n];
            t[n] = y;
        }
        else
            return k;
    }
}

int kty(double t[], int n, int k) {
    int l = partition(n, t);

    // jeśli moc zbioru jest większa lub równa k, 
    // szukamy rekurencyjnie k-tego elementu w zbiocze A<=
    if (k <= l)
        return kty(t, l, k);
    else
        return kty(t + l, n - l, k - l);
}
