#include <stddef.h>

int count_passengers(int stops[][2], size_t n) {
    int total = 0;
    for (size_t i = 0; i < n; i++) {
        total += stops[i][0] - stops[i][1];
    }
    return total;
}