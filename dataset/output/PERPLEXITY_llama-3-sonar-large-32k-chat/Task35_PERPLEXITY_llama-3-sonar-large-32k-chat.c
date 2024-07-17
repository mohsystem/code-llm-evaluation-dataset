#include <stdio.h>

int peopleOnBus(int stops[][2], int size) {
    int people = 0;
    for (int i = 0; i < size; i++) {
        people += stops[i][0] - stops[i][1];
    }
    return people;
}

int main() {
    int stops[][2] = {{10, 0}, {3, 5}, {5, 8}};
    int size = sizeof(stops) / sizeof(stops[0]);
    printf("%d
", peopleOnBus(stops, size));
    return 0;
}