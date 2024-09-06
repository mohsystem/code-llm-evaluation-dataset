#include <stdio.h>

int longestRun(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    int longest = 1;
    int current = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1] + 1 || arr[i] == arr[i-1] - 1) {
            current++;
        } else {
            longest = (longest > current) ? longest : current;
            current = 1;
        }
    }
    return (longest > current) ? longest : current;
}