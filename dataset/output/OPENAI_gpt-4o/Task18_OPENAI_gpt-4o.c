#include <stdio.h>
#include <math.h>

int convertBinaryArrayToInt(int* binaryArray, int length) {
    int result = 0;
    for (int i = 0; i < length; i++) {
        result = result * 2 + binaryArray[i];
    }
    return result;
}

int main() {
    int testCases[8][4] = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 0, 1, 1}
    };

    int lengths[8] = {4, 4, 4, 4, 4, 4, 4, 4};

    for (int i = 0; i < 8; i++) {
        printf("%d
", convertBinaryArrayToInt(testCases[i], lengths[i]));
    }

    return 0;
}