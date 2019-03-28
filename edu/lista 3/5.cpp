#include <iostream>

void merge(int tab[], int start, int mid, int end) {
    int tempStart = mid + 1;

    while (start <= mid && tempStart <= end) {

        if(tab[start] > tab[tempStart]) {
            int value = tab[tempStart];
            int index = tempStart;

            while (index != start) {
                tab[index] = tab[index - 1];
                
                index--;
            }

            tab[start] = value;

            start++;
            mid++;
            tempStart++;
        } else  
            start++;
    }
}



void mergesort(int tab[], int l, int r) {

    if (l < r) {
        int mid = (l + r) / 2;
        
        mergesort(tab, l, mid);
        mergesort(tab, mid + 1, r);
        merge(tab, l, mid, r);
    }
}



int main() {
    int t[] = {9, 3, 8, 2};

    mergesort(t, 0, sizeof(t) / sizeof(t[0]) - 1);

    for(int x : t) { std::cout << x << " "; }
    
}
