#include <stdio.h>

int queueTime(int customers[], int n, int size) {
    int tills[n];
    for (int i = 0; i < n; i++) {
        tills[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        int minIndex = 0;
        for (int j = 1; j < n; j++) {
            if (tills[j] < tills[minIndex]) {
                minIndex = j;
            }
        }
        tills[minIndex] += customers[i];
    }
    int maxTime = 0;
    for (int i = 0; i < n; i++) {
        if (tills[i] > maxTime) {
            maxTime = tills[i];
        }
    }
    return maxTime;
}