
#include <stddef.h>

int number(const int busStops[][2], size_t n) {
    int passengers = 0;
    for (size_t i = 0; i < n; i++) {
        passengers += busStops[i][0] - busStops[i][1];
    }
    return passengers;
}
