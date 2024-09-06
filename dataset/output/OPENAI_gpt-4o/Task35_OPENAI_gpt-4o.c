#include <stdio.h>

typedef struct {
    int on;
    int off;
} Stop;

int numberOfPeople(Stop busStops[], int size) {
    int totalPeople = 0;
    for (int i = 0; i < size; i++) {
        totalPeople += busStops[i].on;
        totalPeople -= busStops[i].off;
    }
    return totalPeople;
}

int main() {
    Stop busStops[] = {{10, 0}, {3, 5}, {5, 8}};
    int size = sizeof(busStops) / sizeof(busStops[0]);
    printf("%d\n", numberOfPeople(busStops, size)); // Output: 5
    return 0;
}