#include <stdlib.h>

int queueTime(int* customers, int customersSize, int n) {
    if (customersSize == 0) {
        return 0;
    }
    int* tills = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < customersSize; i++) {
        int minTill = 0;
        for (int j = 1; j < n; j++) {
            if (tills[j] < tills[minTill]) {
                minTill = j;
            }
        }
        tills[minTill] += customers[i];
    }
    int maxTime = tills[0];
    for (int i = 1; i < n; i++) {
        if (tills[i] > maxTime) {
            maxTime = tills[i];
        }
    }
    free(tills);
    return maxTime;
}