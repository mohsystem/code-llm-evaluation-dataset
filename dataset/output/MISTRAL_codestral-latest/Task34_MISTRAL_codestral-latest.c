#include <stdbool.h>
#include <math.h>

bool narcissistic(int value) {
    int original_value = value;
    int n = 0;
    int sum = 0;

    while (original_value != 0) {
        original_value /= 10;
        ++n;
    }

    original_value = value;

    while (original_value != 0) {
        int remainder = original_value % 10;
        sum += pow(remainder, n);
        original_value /= 10;
    }

    return value == sum;
}