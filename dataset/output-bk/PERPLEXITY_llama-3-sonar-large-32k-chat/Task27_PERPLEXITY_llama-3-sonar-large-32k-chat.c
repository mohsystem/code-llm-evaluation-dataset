#include <stdio.h>

int findOutlier(int integers[], int size) {
    int evenCount = 0;
    int oddCount = 0;
    int evenNum = 0;
    int oddNum = 0;
    
    for (int i = 0; i < size; i++) {
        if (integers[i] % 2 == 0) {
            evenCount++;
            evenNum = integers[i];
        } else {
            oddCount++;
            oddNum = integers[i];
        }
    }
    
    return evenCount == 1 ? evenNum : oddNum;
}

int main() {
    int integers[] = {2, 4, 0, 100, 4, 11, 2602, 36};
    int size = sizeof(integers) / sizeof(integers[0]);
    printf("%d
", findOutlier(integers, size));
    return 0;
}