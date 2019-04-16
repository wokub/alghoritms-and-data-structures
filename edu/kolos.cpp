// STABILNE | złożoność czasowa | złożoność pamięciowa |
// Insertion sort | n^2 | O(1) - stała |
void insertionSort (double t[], int n) {
    // bierzemy kolejny element
    for (int k = 1; k < n; k++) {
        // sprawdzamy ze wszystkimi poprzednimi
        for(int i = k; i > 0 && t[i-1] > t[i]; i--) {
            std::swap(t[i], t[i-1]);    // zamieniamy miejscami
            // warunek porównujący tj. ... i > 0 && t[i-1] > t[i] ...
        }
    }
}
// Counting sort | n^2 | O(1) - stała |
void countingSort (double t[], int n, int max) {
    int output[n];
    int i;
    int count[max] = {0}

    // zliczanie, liczba wystąpień liczb zapisywana
    for(int i = 0; i < n; i++) {
        count[int(t[i])]++;
    }
    // akumulacja, count[i] przechowuje pozycję liczby w output
    for(int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }
    // wpis do bufora, tworzenie końcowej tablicy
    for(int i = n-1; i >= 0; i--) {
        output[--count[int(t[i])]] = t[i];
    }
    // przypisanie, przeniesienie do tablicy
    for(int i = 0; i < n; i++) {
        t[i] = output[i];
    }
}
// Radix Sort

// Bucket Sort

// Merge Sort

// NIESTABILNE
// Quick Sort
int partition (double t[], int n) {
    int k = -1;
    double x = t[n / 2]; // pivot
  
    for(;;) {
        while (t[--n] > x);
        while (t[++k] < x);
        if (k < n) {
            std::swap(t[k],t[n]);
        } else       
            return k;
    }
}

void quickSort (double t[], int n) {
    if (n > 1) {
        int k = partition (t, n); //podziel na dwie czesci
        quick_sort (t, k);	     //posortuj lewa
        quick_sort (t+k, n-k);    //posortuj prawa
    }
}
// Heap Sort