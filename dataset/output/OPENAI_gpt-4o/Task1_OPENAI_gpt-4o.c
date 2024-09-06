#include <stdio.h>

int numberOfPeopleOnBus(int busStops[][2], int size) {
    int peopleOnBus = 0;
    for (int i = 0; i < size; ++i) {
        peopleOnBus += busStops[i][0] - busStops[i][1];
    }
    return peopleOnBus;
}

int main() {
    int busStops[][2] = { {3, 0}, {2, 1}, {5, 2}, {1, 4} };
    int size = sizeof(busStops) / sizeof(busStops[0]);
    printf("%d\n", numberOfPeopleOnBus(busStops, size));
    return 0;
}