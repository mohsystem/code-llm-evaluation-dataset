#include <stdio.h>

int findOutlier(int arr[], int len) {
    int oddCount = 0, evenCount = 0, oddNum = 0, evenNum = 0;
    for (int i = 0; i < len && (oddCount == 0 || evenCount == 0); ++i) {
        if (arr[i] % 2 == 0) {
            evenCount++;
            evenNum = arr[i];
        } else {
            oddCount++;
            oddNum = arr[i];
        }
    }
    return oddCount == 1 ? oddNum : evenNum;
}

int main() {
    int example1[] = {2, 4, 0, 100, 4, 11, 2602, 36};
    int example2[] = {160, 3, 1719, 19, 11, 13, -21};
    int len1 = sizeof(example1) / sizeof(example1[0]);
    int len2 = sizeof(example2) / sizeof(example2[0]);
    printf("%d
", findOutlier(example1, len1));  // Should print 11
    printf("%d
", findOutlier(example2, len2));  // Should print 160
    return 0;
}