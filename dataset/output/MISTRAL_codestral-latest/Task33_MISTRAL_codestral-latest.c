#include <stdlib.h>

int queueTime(const int *customers, int n, int tills) {
    int *till_times = calloc(tills, sizeof(int));
    for (int i = 0; i < n; i++) {
        int min_index = 0;
        for (int j = 1; j < tills; j++) {
            if (till_times[j] < till_times[min_index]) {
                min_index = j;
            }
        }
        till_times[min_index] += customers[i];
    }
    int max_time = 0;
    for (int i = 0; i < tills; i++) {
        if (till_times[i] > max_time) {
            max_time = till_times[i];
        }
    }
    free(till_times);
    return max_time;
}