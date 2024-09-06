#include <stdio.h>

int findOutlier(int integers[], int size) {
    int odds[size], evens[size];
    int odd_count = 0, even_count = 0;

    for (int i = 0; i < size; i++) {
        if (integers[i] % 2 == 0) {
            evens[even_count++] = integers[i];
        } else {
            odds[odd_count++] = integers[i];
        }
    }

    return (odd_count == 1) ? odds[0] : evens[0];
}

int main() {
    int arr1[] = {2, 4, 0, 100, 4, 11, 2602, 36};
    int arr2[] = {160, 3, 1719, 19, 11, 13, -21};
    
    printf("%d\n", findOutlier(arr1, 8));  // Output: 11
    printf("%d\n", findOutlier(arr2, 7));  // Output: 160

    return 0;
}