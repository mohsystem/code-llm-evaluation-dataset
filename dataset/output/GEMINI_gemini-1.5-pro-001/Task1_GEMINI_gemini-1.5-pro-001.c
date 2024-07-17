#include <stdio.h>

int peopleOnBus(int busStops[][2], int stops) {
    int peopleOnBus = 0;
    for (int i = 0; i < stops; i++) {
        peopleOnBus += busStops[i][0] - busStops[i][1];
    }
    return peopleOnBus;
}

int main() {
    int busStops[][2] = {{10, 0}, {3, 5}, {5, 8}};
    int stops = sizeof(busStops) / sizeof(busStops[0]);
    printf("%d
", peopleOnBus(busStops, stops));
    return 0;
}