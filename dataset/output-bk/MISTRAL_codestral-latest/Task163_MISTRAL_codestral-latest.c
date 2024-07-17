#include <stdio.h>

int longestRun(int arr[], int n) {
    if (n == 0) {
        return 0;
    }

    int longestSequence = 1;
    int currentSequence = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1] + 1 || arr[i] == arr[i-1] - 1) {
            currentSequence++;
        } else {
            if (currentSequence > longestSequence) {
                longestSequence = currentSequence;
            }
            currentSequence = 1;
        }
    }

    return (currentSequence > longestSequence) ? currentSequence : longestSequence;
}