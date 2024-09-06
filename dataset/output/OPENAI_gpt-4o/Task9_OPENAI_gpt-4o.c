#include <stdio.h>

const char* sumIsOddOrEven(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum % 2 == 0 ? "even" : "odd";
}

int main() {
    int arr1[] = {0};
    int arr2[] = {0, 1, 4};
    int arr3[] = {0, -1, -5};

    printf("%s\n", sumIsOddOrEven(arr1, 1));      // even
    printf("%s\n", sumIsOddOrEven(arr2, 3));      // odd
    printf("%s\n", sumIsOddOrEven(arr3, 3));      // even

    return 0;
}