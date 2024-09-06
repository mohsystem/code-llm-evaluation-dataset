
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int queue_time(const int *customers, int customers_length, int n) {
    int tills[n];
    for (int i = 0; i < n; i++) {
        tills[i] = 0;
    }
    
    for (int i = 0; i < customers_length; i++) {
        tills[0] += customers[i];
        qsort(tills, n, sizeof(int), compare);
    }
    
    int max_time = tills[0];
    for (int i = 1; i < n; i++) {
        if (tills[i] > max_time) {
            max_time = tills[i];
        }
    }
    
    return max_time;
}
