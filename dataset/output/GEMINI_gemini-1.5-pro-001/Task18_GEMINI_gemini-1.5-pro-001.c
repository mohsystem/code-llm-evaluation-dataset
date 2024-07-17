#include <stdio.h>
#include <math.h>

int binaryArrayToInteger(int binaryArray[], int arrayLength) {
    int decimalValue = 0;
    for (int i = 0; i < arrayLength; i++) {
        if (binaryArray[i] == 1) {
            decimalValue += pow(2, arrayLength - 1 - i);
        }
    }
    return decimalValue;
}

int main() {
    int binaryArray1[] = {0, 0, 0, 1};
    int binaryArray2[] = {0, 0, 1, 0};
    int binaryArray3[] = {0, 1, 0, 1};
    int binaryArray4[] = {1, 0, 0, 1};
    int binaryArray5[] = {0, 0, 1, 0};
    int binaryArray6[] = {0, 1, 1, 0};
    int binaryArray7[] = {1, 1, 1, 1};
    int binaryArray8[] = {1, 0, 1, 1};

    printf("%d
", binaryArrayToInteger(binaryArray1, 4)); // Output: 1
    printf("%d
", binaryArrayToInteger(binaryArray2, 4)); // Output: 2
    printf("%d
", binaryArrayToInteger(binaryArray3, 4)); // Output: 5
    printf("%d
", binaryArrayToInteger(binaryArray4, 4)); // Output: 9
    printf("%d
", binaryArrayToInteger(binaryArray5, 4)); // Output: 2
    printf("%d
", binaryArrayToInteger(binaryArray6, 4)); // Output: 6
    printf("%d
", binaryArrayToInteger(binaryArray7, 4)); // Output: 15
    printf("%d
", binaryArrayToInteger(binaryArray8, 4)); // Output: 11

    return 0;
}