#include <stdio.h>
#include <stdlib.h>

int number(int** busStops, int stopsCount, int* stopsSizes) {
    int peopleInBus = 0;
    for (int i = 0; i < stopsCount; i++) {
        peopleInBus += busStops[i][0] - busStops[i][1];
    }
    return peopleInBus;
}