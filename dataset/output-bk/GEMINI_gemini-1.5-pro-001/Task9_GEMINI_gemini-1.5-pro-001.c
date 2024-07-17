#include <stdio.h>
#include <stdlib.h>

char * odd_or_even(int * array, int array_size) {
    int sum = 0;
    for (int i = 0; i < array_size; i++) {
        sum += array[i];
    }
    if (sum % 2 == 0) {
        return "even";
    } else {
        return "odd";
    }
}