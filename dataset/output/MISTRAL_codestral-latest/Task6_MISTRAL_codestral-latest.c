#include <stdio.h>

double findUniq(double arr[], int n) {
    int i;
    double a = arr[0];
    double b = arr[1];
    for (i = 2; i < n; i++) {
        if (arr[i] != a) {
            b = arr[i];
            break;
        }
    }
    int count_a = 0, count_b = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == a) {
            count_a++;
        } else if (arr[i] == b) {
            count_b++;
        }
    }
    return count_a == 1 ? a : b;
}