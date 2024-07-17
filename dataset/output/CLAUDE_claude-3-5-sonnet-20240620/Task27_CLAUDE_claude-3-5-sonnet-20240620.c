
#include <stdio.h>

int findOutlier(int* integers, int size) {
    int oddCount = 0, evenCount = 0;
    int lastOdd = 0, lastEven = 0;

    for (int i = 0; i < size; i++) {
        if (integers[i] % 2 == 0) {
            evenCount++;
            lastEven = integers[i];
        } else {
            oddCount++;
            lastOdd = integers[i];
        }

        if (i >= 2) {
            if (oddCount == 1 && evenCount > 1) return lastOdd;
            if (evenCount == 1 && oddCount > 1) return lastEven;
        }
    }

    return oddCount == 1 ? lastOdd : lastEven;
}

int main() {
    int arr1[] = {2, 4, 0, 100, 4, 11, 2602, 36};
    int arr2[] = {160, 3, 1719, 19, 11, 13, -21};

    printf("%d\
", findOutlier(arr1, sizeof(arr1) / sizeof(arr1[0])));
    printf("%d\
", findOutlier(arr2, sizeof(arr2) / sizeof(arr2[0])));

    return 0;
}
