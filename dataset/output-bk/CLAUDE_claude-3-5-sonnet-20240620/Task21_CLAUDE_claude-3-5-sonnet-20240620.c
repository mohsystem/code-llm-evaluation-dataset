
#include <stdlib.h>

int* removeSmallest(int* numbers, int numbersSize, int* resultSize) {
    if (numbersSize == 0) {
        *resultSize = 0;
        return NULL;
    }

    int* result = (int*)malloc((numbersSize - 1) * sizeof(int));
    int minIndex = 0;
    for (int i = 1; i < numbersSize; i++) {
        if (numbers[i] < numbers[minIndex]) {
            minIndex = i;
        }
    }

    int j = 0;
    for (int i = 0; i < numbersSize; i++) {
        if (i != minIndex) {
            result[j++] = numbers[i];
        }
    }

    *resultSize = numbersSize - 1;
    return result;
}
