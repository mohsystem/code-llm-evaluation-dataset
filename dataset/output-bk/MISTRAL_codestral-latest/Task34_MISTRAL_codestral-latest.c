#include <stdio.h>
#include <math.h>

int narcissistic(int value) {
    int original, remainder, n = 0, result = 0;

    original = value;

    while (original != 0) {
        original /= 10;
        ++n;
    }

    original = value;

    while (original != 0) {
        remainder = original % 10;
        result += pow(remainder, n);
        original /= 10;
    }

    return value == result;
}