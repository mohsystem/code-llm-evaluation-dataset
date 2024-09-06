#include <stdio.h>

int number_of_people_still_on_bus(int people[][2], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        count += people[i][0] - people[i][1];
    }
    return count;
}