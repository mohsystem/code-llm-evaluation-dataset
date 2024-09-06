#include <stdio.h>
#include <stdlib.h>

int number(int bus_stops[][2], int stops_count) {
    int people_on_bus = 0;
    for (int i = 0; i < stops_count; i++) {
        people_on_bus += bus_stops[i][0] - bus_stops[i][1];
    }
    return people_on_bus;
}