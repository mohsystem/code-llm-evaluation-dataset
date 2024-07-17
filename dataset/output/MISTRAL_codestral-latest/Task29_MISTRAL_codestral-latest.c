#include <stdio.h>

void twoSum(int* numbers, int numbersSize, int target, int* returnSize, int* returnIndexes) {
    int numMap[10000] = {0}; // Assuming the range of numbers is within 0 to 9999
    for (int i = 0; i < numbersSize; i++) {
        if (numMap[target - numbers[i]] != 0) {
            returnIndexes[0] = numMap[target - numbers[i]] - 1;
            returnIndexes[1] = i;
            *returnSize = 2;
            return;
        }
        numMap[numbers[i]] = i + 1;
    }
    *returnSize = 0;
}