#include <stdio.h>

int number_of_people_still_on_bus(int lst[][2], int size) {
    int people_on_bus = 0;
    for (int i = 0; i < size; i++) {
        people_on_bus += lst[i][0] - lst[i][1];
    }
    return people_on_bus;
}