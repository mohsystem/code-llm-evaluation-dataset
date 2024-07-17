#include <stdio.h>

double findUniq(double arr[], int n) {
    if (arr[0] != arr[1] && arr[0] != arr[2]) return arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] != arr[i - 1]) return arr[i];
    return 0;
}