#include <iostream>
#include <cmath>

int half(double minVal, double maxVal) {
    double s;

    for(int i = minVal; i <= maxVal; i++) {
        s++;
    }
    if(s == 1) {
        return 0;
    } else if((int)s % 2 != 0) {
        return (int)(minVal + (s - 1) / 2);
    } else
        return (int)(minVal + (s / 2) - 1);
}

void maxValueR(int values[], int m, double minVal, double maxVal){
    int h = half(minVal, maxVal);

    if(values[h] == m) {
        std::cout << "Number " << m << "\nSpot " << h << std::endl;
    } else if (values[h] > m) {
        maxValueR(values, m, minVal, values[h]);
    } else
        maxValueR(values, m, values[h], maxVal);
}

int main() {
    int n = 100;
    int tab[n];

    for (int i = 0; i < n; i++) {
        tab[i] = i+1; // ++
    }

    maxValueR(tab, 20, 0, n);

    return 0;
}
