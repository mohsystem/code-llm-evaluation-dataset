
#include <stdio.h>
#include <stdlib.h>

int findOutlier(int* arr, int size) {
    int evenCount = 0, oddCount = 0;
    int evenNum = 0, oddNum = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
            evenNum = arr[i];
        } else {
            oddCount++;
            oddNum = arr[i];
        }

        if (evenCount > 1 && oddCount == 1) return oddNum;
        if (oddCount > 1 && evenCount == 1) return evenNum;
    }

    return evenCount == 1 ? evenNum : oddNum;
}

int main() {
    int arr1[] = {2, 4, 0, 100, 4, 11, 2602, 36};
    int arr2[] = {160, 3, 1719, 19, 11, 13, -21};

    printf("%d\\n", findOutlier(arr1, sizeof(arr1) / sizeof(arr1[0])));  // Output: 11
    printf("%d\\n", findOutlier(arr2, sizeof(arr2) / sizeof(arr2[0])));  // Output: 160

    return 0;
}
