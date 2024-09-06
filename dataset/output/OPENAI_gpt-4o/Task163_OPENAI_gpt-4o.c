#include <stdio.h>

int longestRun(int* lst, int length) {
    if (length == 0) {
        return 0;
    }
    int maxRun = 1;
    int currentRun = 1;
    for (int i = 1; i < length; ++i) {
        if (lst[i] == lst[i-1] + 1 || lst[i] == lst[i-1] - 1) {
            currentRun += 1;
        } else {
            if (currentRun > maxRun) {
                maxRun = currentRun;
            }
            currentRun = 1;
        }
    }
    return (currentRun > maxRun) ? currentRun : maxRun;
}

int main() {
    int arr1[] = {1, 2, 3, 5, 6, 7, 8, 9};
    int arr2[] = {1, 2, 3, 10, 11, 15};
    int arr3[] = {5, 4, 2, 1};
    int arr4[] = {3, 5, 7, 10, 15};

    printf("%d\n", longestRun(arr1, 8));
    printf("%d\n", longestRun(arr2, 6));
    printf("%d\n", longestRun(arr3, 4));
    printf("%d\n", longestRun(arr4, 5));

    return 0;
}