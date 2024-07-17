#include <stdio.h>

int peopleOnTheBus(int stops[][2], int size) {
    int peopleOnBus = 0;
    for(int i = 0; i < size; i++) {
        peopleOnBus += stops[i][0] - stops[i][1];
    }
    return peopleOnBus;
}

int main() {
    int stops[3][2] = {{10, 0}, {3, 5}, {2, 5}};
    int size = sizeof(stops) / sizeof(stops[0]);
    printf("%d
", peopleOnTheBus(stops, size)); // Output should be 5
    return 0;
}