#include <stddef.h>

int countPassengers(int stops[][2], size_t len) {
    int total = 0;
    for (size_t i = 0; i < len; i++) {
        total += stops[i][0] - stops[i][1];
    }
    return total;
}