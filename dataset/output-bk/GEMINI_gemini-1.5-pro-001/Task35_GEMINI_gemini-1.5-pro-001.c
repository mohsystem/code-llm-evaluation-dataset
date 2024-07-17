#include <stdio.h>

int getNumberOfPeopleOnBus(int busStops[][2], int numStops) {
    int peopleOnBus = 0;

    for (int i = 0; i < numStops; i++) {
        peopleOnBus += busStops[i][0] - busStops[i][1];
    }

    return peopleOnBus;
}

int main() {
    // Test cases
    int busStops1[][2] = {{10, 0}, {3, 5}, {5, 8}};
    int busStops2[][2] = {{3, 0}, {9, 1}, {4, 10}, {12, 2}, {6, 1}, {7, 10}};
    int busStops3[][2] = {{3, 0}, {9, 1}, {4, 8}, {12, 2}, {6, 1}, {7, 8}};

    printf("%d
", getNumberOfPeopleOnBus(busStops1, sizeof(busStops1) / sizeof(busStops1[0]))); // 5
    printf("%d
", getNumberOfPeopleOnBus(busStops2, sizeof(busStops2) / sizeof(busStops2[0]))); // 17
    printf("%d
", getNumberOfPeopleOnBus(busStops3, sizeof(busStops3) / sizeof(busStops3[0]))); // 21

    return 0;
}