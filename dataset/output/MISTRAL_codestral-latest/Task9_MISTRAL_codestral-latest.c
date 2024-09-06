#include <stdio.h>

const char* oddOrEven(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum % 2 == 0 ? "even" : "odd";
}