
#include <stdio.h>

int countPassengers(int stops[][2], int size) {
    int passengers = 0;
    for (int i = 0; i < size; i++) {
        passengers += stops[i][0] - stops[i][1];
    }
    return passengers;
}

int main() {
    int stops[][2] = {{10, 0}, {3, 5}, {2, 5}};
    int size = sizeof(stops) / sizeof(stops[0]);
    printf("%d\
", countPassengers(stops, size));  // Output: 5
    return 0;
}
