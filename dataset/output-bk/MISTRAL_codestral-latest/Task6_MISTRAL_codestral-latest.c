// C
#include <stdio.h>

double findUniq(const double arr[], int n) {
    double a = arr[0];
    double b = arr[1];
    double c = arr[2];

    if (a != b && a != c) return a;
    if (a != b) return c;

    for (int i = 3; i < n; i++) {
        if (arr[i] != a) return arr[i];
    }

    return -1;
}