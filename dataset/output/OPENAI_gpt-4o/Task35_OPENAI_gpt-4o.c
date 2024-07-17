#include <stdio.h>

int peopleOnBus(int busStops[][2], int size) {
    int people = 0;
    for (int i = 0; i < size; i++) {
        people += busStops[i][0];
        people -= busStops[i][1];
    }
    return people;
}

int main() {
    int busStops[][2] = {{3, 0}, {2, 1}, {5, 3}, {2, 2}};
    int size = sizeof(busStops) / sizeof(busStops[0]);
    printf("%d
", peopleOnBus(busStops, size));
    return 0;
}