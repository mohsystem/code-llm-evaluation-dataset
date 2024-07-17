#include <stdlib.h>
#include <stdio.h>

int queue_time(const int *customers, int customers_len, int n) {
    int *tills = calloc(n, sizeof(int));
    for (int i = 0; i < customers_len; i++) {
        int minIndex = 0;
        for (int j = 1; j < n; j++) {
            if (tills[j] < tills[minIndex]) {
                minIndex = j;
            }
        }
        tills[minIndex] += customers[i];
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (tills[i] > max) {
            max = tills[i];
        }
    }
    free(tills);
    return max;
}