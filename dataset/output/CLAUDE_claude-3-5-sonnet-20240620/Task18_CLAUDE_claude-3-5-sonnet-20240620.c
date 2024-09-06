
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convertBinaryArrayToInt(int* binary, int size) {
    char* binaryString = (char*)malloc((size + 1) * sizeof(char));
    for (int i = 0; i < size; i++) {
        binaryString[i] = binary[i] + '0';
    }
    binaryString[size] = '\\0';
    
    int result = (int)strtol(binaryString, NULL, 2);
    free(binaryString);
    return result;
}

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]");
}

int main() {
    int testCases[][4] = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 0, 1, 1}
    };

    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numTestCases; i++) {
        printf("Testing: ");
        printArray(testCases[i], 4);
        printf(" ==> %d\\n", convertBinaryArrayToInt(testCases[i], 4));
    }

    return 0;
}
