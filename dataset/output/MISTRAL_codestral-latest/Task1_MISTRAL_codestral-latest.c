// C
#include <stddef.h>

int count_passengers(size_t sz, int stops[sz][2]) {
    int total = 0;
    for (size_t i = 0; i < sz; i++) {
        total += stops[i][0] - stops[i][1];
    }
    return total;
}