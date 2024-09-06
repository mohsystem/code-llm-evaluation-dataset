#include <stdio.h>

int binaryArrayToInt(int* arr, int length) {
    int result = 0;
    for (int i = 0; i < length; i++) {
        result = (result << 1) | arr[i];
    }
    return result;
}

int main() {
    int test_cases[][4] = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 0, 1, 1}
    };
    int num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_test_cases; i++) {
        printf("Testing: [ ");
        for (int j = 0; j < 4; j++) {
            printf("%d ", test_cases[i][j]);
        }
        printf("] ==> %d\n", binaryArrayToInt(test_cases[i], 4));
    }

    return 0;
}