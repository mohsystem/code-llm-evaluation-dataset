#include <stdio.h>

const char* oddOrEven(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return (sum % 2 == 0) ? "even" : "odd";
}

int main() {
    int array[] = {0, -1, -5};
    int size = sizeof(array) / sizeof(array[0]);
    printf("%s
", oddOrEven(array, size));
    return 0;
}