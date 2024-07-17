#include <stdio.h>

void twoSum(int numbers[], int target, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (numbers[i] + numbers[j] == target) {
                printf("(%d, %d)
", i, j);
                return;
            }
        }
    }
}