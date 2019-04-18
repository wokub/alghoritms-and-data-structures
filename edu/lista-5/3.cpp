void countingSort(int t[], int n, int c) {
    int tmp[n];
    int x[10] = {0};

    for (int i = 0; i < n; i++)
        x[(t[i] / c) % 10]++;

    for (int i = 1; i < 10; i++)
        x[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        tmp[x[(t[i] / c) % 10] - 1] = t[i];
        x[(t[i] / c) % 10]--;
    }

    for (int i = 0; i < n; i++)
        t[i] = tmp[i];
}
